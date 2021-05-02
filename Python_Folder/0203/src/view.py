import matplotlib.pyplot as plt
from jieba import analyse
from wordcloud import WordCloud

# text = open(r'./0203/data/疯狂原始人2.csv', "r", encoding='utf-8').read()
text = open(r'./0203/data/history.txt', "r", encoding='unicode_escape').read()
tags = analyse.extract_tags(text,  topK=300, withWeight=False)
new_text = ' '.join(tags)
stopwords = set('')

stopwords.update(['SFKY', 'Documents', 'Programming', 'principle','hello','Folder'
                  'Library', 'meaple', 'Frameworks', 'framework', 'Version', 'Demo','zshrc','Users','usr'])
wc = WordCloud(
    font_path="./0203/img/font.ttc",
    background_color="white",
    mask=plt.imread(
        "./0203/img/map.jpg"),
    max_words=300,
    width=768,
    stopwords=stopwords,
    height=2048,

).generate(new_text)
plt.imshow(wc, cmap='rainbow', interpolation='bilinear')
plt.figure('db.wordcloud')
plt.axis('off')
wc.to_file('./0203/img/cloud.png')
