import os
import time
import random
import jieba
import numpy as np
import matplotlib.pyplot as plt
from itertools import chain
from sklearn.metrics import classification_report
from sklearn.metrics import precision_recall_curve
from sklearn.naive_bayes import MultinomialNB
from sklearn.feature_extraction.text import TfidfVectorizer

filenum = 6300
# 读取停用词
def make_words_set(words_file):
    words_set = set()
    with open(words_file, 'r',encoding='utf-8') as fp:
        for line in fp.readlines():
            word = line.strip()
            if len(word)>0 and word not in words_set: # 去重
                words_set.add(word)
    return words_set

# 读入文件，分词后写入中间表
def read_write(datafile,tempfile):
    global filenum
    with open(datafile,'r',encoding='utf-8') as fp:
        wd=fp.read()
        wd = wd.replace('腾讯科技', '')
        wd = wd.replace('腾讯财经', '')
        wd = wd.replace('腾讯体育', '')
        wd = wd.replace('腾讯汽车', '')
        wd = wd.replace('腾讯娱乐', '')
        wd = wd.replace('腾讯房产', '')
        wd = wd.replace('人民网', '')
        wd = wd.replace('新华网', '')
        wd = wd.replace('中新网', '')
        if len(wd)<=1:
            filenum = filenum - 1
            return
        wd_cut=jieba.cut(wd)
        wd_result=' '.join(wd_cut)
        with open(tempfile, 'w',encoding='utf-8') as fw:
            fw.write(wd_result)
        fw.close()
    fp.close() 

# 分词后写入中间表--训练集
datapath = r'./bayes/data/training'
temppath = r'./bayes/temp/train'
files=os.listdir(datapath)
for f in files:
    datafile=os.path.join(datapath,f)
    tempfile=os.path.join(temppath,f)
    read_write(datafile,tempfile)

# 读取中间表数据--训练集
trains=[]
y_train=[]
files=os.listdir(temppath)
for f in files:
    tempfile=os.path.join(temppath,f)
    with open(tempfile,'r',encoding='utf-8') as fp:  
        result=fp.read()
        trains.append(result)
        y_train.append(f[0].split('_')[0])
    fp.close()
# 分词后写入中间表--测试集
datapath = r'./bayes/data/test'
temppath = r'./bayes/temp/test'
files=os.listdir(datapath)
for f in files:
    datafile=os.path.join(datapath,f)
    tempfile=os.path.join(temppath,f)
    read_write(datafile,tempfile)

# 读取中间表数据--测试集
tests=[]
y_test=[]
files=os.listdir(temppath)
for f in files:
    tempfile=os.path.join(temppath,f)
    with open(tempfile,'r',encoding='utf-8') as fp:  
        result=fp.read()
        tests.append(result)
        y_test.append(f[0].split('_')[0])
    fp.close()

# 获取停用词
stop_words=make_words_set(r'./bayes/docs/stop_words.txt')
stop_word=list(stop_words)

# 特征处理，TF-IDF特征处理方法
vector = TfidfVectorizer(stop_words=stop_word)
x_train = vector.fit_transform(trains)
x_test = vector.transform(tests)

clf = MultinomialNB().fit(x_train, y_train)
score = clf.score(x_test,y_test)
print(score)

# 找出每个文件最大的TF-IDF值及其对应的词
wordlist = vector.get_feature_names()
weightlist = x_train.toarray()
with open (r'./bayes/docs/Classify.csv','w',encoding='gbk') as fp:
    xx = "种类,TF-IDF,关键词"
    fp.write(xx)
    for i in range(0,filenum):
        x0=y_train[i]
        if x0 == '1':
            x0 = '财经'
        elif x0 == '2':
            x0 = '科技'
        elif x0 == '3':
            x0 = '汽车'
        elif x0 == '4':
            x0 = '房产'
        elif x0 == '5':
            x0 = '体育'
        elif x0 == '6':
            x0 = '娱乐'
        elif x0 == '7':
            x0 = '其他'
        x=np.where(weightlist[i]==np.max(weightlist[i]))
        x1=x[0].tolist()
        x2=np.max(weightlist[i])
        if len(x1)==1:
            x3=wordlist[x1[0]]
        else:
            x3=[]
            x3.append(wordlist[x1[0]])
        xx="\n%s,%s,%s"%(str(x0),str(x2),x3)
        fp.write(xx)
fp.close()