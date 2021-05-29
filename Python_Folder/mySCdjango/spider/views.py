import json
import os
import sys
import base64

from pathlib import Path

from django.shortcuts import render
from django.http import HttpResponse

from spider.yolov5 import detect

def index(request):
    s = request.POST
    # prefix = s['img'][:(s['img'].find('base64,') + 6)]
    baseUrl = s['img'][(s['img'].find('base64,') + 7):]
    
    imgGer(baseUrl)

    detectDemo()
    print(sys.path)
    print("******************************")
    data = {
        "code": '200',
        "msg": '成功',
        "data": '微信发送成功',
        "total": 1
    }
    return HttpResponse(json.dumps(data,ensure_ascii=False), content_type="application/json", charset='utf-8',status='200',reason='success')

def imgGer(baseUrl):
    imgdata = base64.b64decode(baseUrl)
    file = open('1.jpg', 'wb')
    file.write(imgdata)
    file.close()
