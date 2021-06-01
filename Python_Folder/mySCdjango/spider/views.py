import json
import base64
from django.http import HttpResponse
from .models import Image


def index(request):
    s = request.POST
    # prefix = s['img'][:(s['img'].find('base64,') + 6)]
    baseUrl = s['img'][(s['img'].find('base64,') + 7):]
    imgPost(baseUrl)

    print("******************************")
    data = {
        "code": '200',
        "msg": '成功',
        "data": '微信发送成功',
        "total": 1
    }
    return HttpResponse(json.dumps(data, ensure_ascii=False), content_type="application/json", charset='utf-8', status='200', reason='success')


def imgPost(baseUrl):
    imgdata = base64.b64decode(baseUrl)
    new_img = Image(
        name=str("1.jpg"),
        image=imgdata
    )
    new_img.save()
