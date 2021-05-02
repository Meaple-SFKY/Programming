# Python网络爬虫与信息提取



## 1. Requests库

- `requests.request()`

- `r = requests.get(url)`
  - `r.status_code  //200表示成功，404表示失败`
  - `r.text         //HTTP响应内容的字符串形式`
  - `r.rencoding    //从HTTP header中猜测响应内容的编码方式`
  - `r.apparent_encoding    //从响应内容中析出编码方式（备选编码方式）`
  - `r.content      //HTTP响应内容的二进制形式`
- `requests.head()`
- `requests.post()`
- `requests.put()`
- `requests.patch()`
- `requests.delete()`
- Requests库的异常
  - `requests.ConnectionError    //网络连接错误异常`
  - `requests.HTTPError          //HTTP错误异常`
  - `requests.URLRequired        //URL缺失异常`
  - `requests.TooManyRedirects   //超过最大重定向次数，重定向异常`
  - `requests.ConnectionTimeout  //连接远程服务器超时异常`
  - `requests.Timeout            //请求URL超时，产生超时异常`
- 

