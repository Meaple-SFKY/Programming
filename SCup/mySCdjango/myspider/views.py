import json
import base64
from django.http import HttpResponse
from .models import Image
from .models import CurImg
from .models import Material
import os


def index(request):
    s = request.POST
    baseUrl = s['img'][(s['img'].find('base64,') + 7):]
    nameTime = s['nameTime']
    imgPost(baseUrl, nameTime)
    fp = open("../Caches/name_cache", "w", encoding='utf8')
    fp.write(nameTime)
    fp.close()
    os.system("sh ./my.sh")
    sqCurImg = list(CurImg.objects.filter(iName=nameTime).values('insectName', 'detImg'))[0]
    sqImg = sqCurImg['detImg']
    sqName = str(sqCurImg['insectName'])
    sqMaterial = list(Material.objects.filter(insectName=sqName).values('insectName', 'describe'))[0]
    describe = sqMaterial['describe']
    data = {
        "id": '虫虫百科',
        "msg": '成功',
        "data": sqName,
        "contend": describe,
        "total": 2,
        "img": str(sqImg, 'utf-8')
    }
    return HttpResponse(json.dumps(data, ensure_ascii=False), content_type="application/json", charset='utf-8', status='200', reason='success')


def imgPost(baseUrl, name):
    imgdata = base64.b64decode(baseUrl)
    new_img = Image(
        name=str(name),
        image=imgdata
    )
    new_img.save()
