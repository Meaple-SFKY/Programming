f = open('./img/0.jpg', 'rb')
data = f.read()

fp = open('./loadImg/0.jpg', 'wb')
fp.write(data)
f.close
fp.close