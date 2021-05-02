# 代码结构
```python
import ......
# 读取停用词
def make_words_set(words_file):
	......
# 读入文件，分词后写入中间表
def read_write(datafile,tempfile):
	......
# 分词后写入中间表--训练集
	......
# 读取中间表数据--训练集
	......
# 分词后写入中间表--测试集
	......
# 读取中间表数据--测试集
	......
# 获取停用词
stop_words=make_words_set(r'./bayes/docs/stop_words.txt')
stop_word=list(stop_words)
# 特征处理，TF-IDF特征处理方法
vector = TfidfVectorizer(stop_words=stop_word)
......
# 对模型进行评估
clf = MultinomialNB().fit(x_train, y_train)
score = clf.score(x_test,y_test)
print(score)
# 找出每个文件最大的TF-IDF值及其对应的词
wordlist = vector.get_feature_names()
weightlist = x_train.toarray()
# 将分类结果存入文件
with open (r'./bayes/docs/Classify.csv','w',encoding='gbk') as fp:
	......
......
```