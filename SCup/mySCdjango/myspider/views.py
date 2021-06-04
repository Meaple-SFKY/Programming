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
    # data = {
    #     "code": '200',
    #     "msg": '成功',
    #     "data": '微信发送成功',
    #     "insect": insect,
    #     "total": 1
    # }
    data = {
        "id": '虫虫百科',
        "msg": '成功',
        "data": insect,
        "contend":'李沁，1990年9月27日出生于江苏省苏州市昆山市巴城镇，中国内地影视女演员。'
                  '2008年，李沁因在古装剧《红楼梦》中饰演少年薛宝钗而被观众熟知。2010年，'
                  '凭借在建党九十周年献礼片《建党伟业》中饰演杨开慧获得第31届大众电影百花奖最佳新人奖提名'
                  ' [1-3]  。2013年，主演的现代剧《守望的天空》获得了中美电影节优秀中国电视剧金天使奖；'
                  '而其主演的都市剧《璀璨人生》则获得了全国同时段电视剧收视冠军。2014年，李沁获得了国剧盛典最具潜力女演员奖 [4]'
                  '  。2015年，相继主演青春片《致青春·原来你还在这里》、电视剧版《白鹿原》。2016年，除了出演电影版《微微一笑很倾城》 '
                  '[5/]  ；她还主演了爱情片《闭嘴！爱吧》 [6]  。2018年，凭借建军九十周年献礼片《建军大业》获得第34'
                  '届大众电影百花奖最佳女主角提名 [7-8]  。2019年，主演的古装剧《庆余年》播出 [9-10]  。',
        "total": 2,
        "img":s['img']
    }
    return HttpResponse(json.dumps(data, ensure_ascii=False), content_type="application/json", charset='utf-8', status='200', reason='success')


def imgPost(baseUrl, name):
    imgdata = base64.b64decode(baseUrl)
    new_img = Image(
        name=str(name),
        image=imgdata
    )
    new_img.save()
