import pymysql

conn = pymysql.connect(
	host="localhost",
	port=3306,
	user="root",
	passwd="ppqq8888",
	db="pic",
	charset="utf8"
)

cursor = conn.cursor()
f = open('./img/0.jpg', 'rb')
data = f.read()

cursor.execute('insert into image(id,image1) values (00001,"%s")', data)
f.flush

f = open('./img/1.jpg', 'rb')
data = f.read()

cursor.execute('insert into image(id,image1) values (00002,"%s")', data)
f.close

fp = open('./loadImg/0.jpg', 'wb')
cursor.execute('select image1 from image where id = 1')
newData = cursor.fetchone()[0]
fp.write(newData)
fp.close

conn.commit()
conn.close()
cursor.close()


# cursor = conn.cursor()
# f = open('./loadImg/0.txt', 'wb')

# cursor.execute('select image1 from image where id = 1')
# f.write(cursor.fetchone()[0])
# f.close

# conn.commit()
# conn.close()
# cursor.close()
