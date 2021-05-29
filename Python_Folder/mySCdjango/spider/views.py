import json

from django.shortcuts import render
from django.http import HttpResponse


def index(request):
    s = request.POST
    print(s['img'])
    data = {
        "code": '200',
        "msg": '成功',
        "data": '微信发送成功',
        "total": 1
    }
    return HttpResponse(json.dumps(data,ensure_ascii=False), content_type="application/json", charset='utf-8',status='200',reason='success')
