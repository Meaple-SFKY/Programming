import pymysql as mdb

conn = mdb.connect(host='localhost',user='root',passwd='ppqq8888',db='pic')
cursor = conn.cursor()
cursor.execute("SELECT image FROM spider_image LIMIT 1")

image = cursor.fetchone()[0]
file = open('img/2.jpg', 'wb')
file.write(image)
file.close()
cursor.close()
conn.close()
