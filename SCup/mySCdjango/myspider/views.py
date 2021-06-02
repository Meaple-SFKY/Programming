import json
import base64
from django.http import HttpResponse
from .models import Image
import os


def index(request):
    s = request.POST
    # prefix = s['img'][:(s['img'].find('base64,') + 6)]
    baseUrl = s['img'][(s['img'].find('base64,') + 7):]
    nameTime = s['nameTime']
    imgPost(baseUrl, nameTime)
    fp = open("../Caches/name_cache", "w", encoding='utf8')
    fp.write(nameTime)
    fp.close()
    os.system("sh ./my.sh")
    fp = open("../Caches/detect_cache", "r", encoding='utf8')
    insect = fp.read()
    fp.close()

    print("******************************")
    data = {
        "code": '200',
        "msg": '成功',
        "data": '微信发送成功',
        "insect": insect,
        "total": 1
    }
    return HttpResponse(json.dumps(data, ensure_ascii=False), content_type="application/json", charset='utf-8', status='200', reason='success')


def imgPost(baseUrl, name):
    imgdata = base64.b64decode(baseUrl)
    new_img = Image(
        name=str(name),
        image=imgdata
    )
    new_img.save()
