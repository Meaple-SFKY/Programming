import pymysql
import base64

fp = open("img/1.jpg", 'rb')
img = fp.read()
code = base64.b64encode(img)
fp.close()

database = pymysql.connect(host="localhost", user="root", passwd="ppqq8888", db="pic")
cursor = database.cursor()
sql = "INSERT INTO spider_image (image) VALUES  (%s);"
args = (code)
file1 = open('img/3.txt', 'wb')
file1.write(code)
file1.close()
cursor.execute(sql, args)
database.commit()
cursor.close()
database.close()

print("============")
print("Done! ")
