import requests
import json
import pandas as pd
import os
import tkinter as tk
import time
import openpyxl

# 爬取源数据地址"https://news.qq.com/zt2020/page/feiyan.htm"（腾讯新闻）
# 分析网页的Network后，发现需要的数据在这个url中请求
url = "https://view.inews.qq.com/g2/getOnsInfo?name=disease_h5"

#  修改头，让浏览器不发觉是代码在下载数据
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3314.0 Safari/537.36 SE 2.X MetaSr 1.0'
}

# 数据存储结构
nCovDataColumns = ['名称', '新增确诊', '累积确诊', '死亡', '死亡率', '治愈', '治愈率']
df_nCovData = pd.DataFrame(columns=nCovDataColumns)

# 创建并打开交互窗口
root = tk.Tk()
root.title('2019-nCovDataCrawl')
root.iconbitmap('icon.ico')
processLabel = tk.Label(root, text='', fg='RED', padx=10, pady=10)


def open_win():
    group1 = tk.LabelFrame(root, text='程序说明', padx=5, pady=5)
    group1.pack(padx=10, pady=10)
    dataInfo = tk.Label(group1, text='该程序用于爬取腾讯发布的...导致的人员伤亡数据，'
                                     '\n数据存储于epidemicData文件夹下的excel文件，以爬取的数据发布时间命名，'
                                     '\n具体包括字段为：名称，新增确诊，累积确诊，死亡，死亡率，治愈，治愈率，\n'
                                     '数据包括省，以及其下的市级数据，省级数据行下紧跟市级数据行\n'
                                     '【单次爬取数据】用于手动爬取操作，【自动爬取数据】用于自动每半小时爬取一次数据\n'
                                     '收集该数据只为方便他人研究，为这场抗"疫"战做一份贡献，欢迎使用本程序获取研究数据！')
    dataInfo.pack()
    frame1 = tk.Frame(root)
    frame1.pack(side=tk.RIGHT)
    btnCrawl_Click = tk.Button(frame1, text='单次爬取数据', command=crawl_data)
    btnCrawl_Click.pack(side=tk.LEFT, padx=10, pady=10)

    btnCrawl_Auto = tk.Button(frame1, text='自动爬取数据', command=timeWork)
    btnCrawl_Auto.pack(side=tk.LEFT, padx=10, pady=10)

    btnCancel = tk.Button(frame1, text='关闭', command=root.quit)
    btnCancel.pack(side=tk.RIGHT, padx=10, pady=10)

    root.mainloop()


# 打开url,返回json格式的数据
def open_url():
    r = requests.get(url, headers=headers)
    jsonData = r.json()
    return json.loads(jsonData['data'])


# 获取数据更新的时间，用于将不同更新时间的数据都爬取下来
def getUpdataTime(jsonData):
    lastUpdateTime = jsonData['lastUpdateTime']
    return lastUpdateTime


''' 
jsonData数据说明 ：
today:{confirm---新增确诊}

total:{confirm---累积确诊,dead--死亡，deadRate死亡率，heal---治愈，healRate---治愈率}

'''


# 获取数据字典
def getDataDic(jsonData):
    name = jsonData['name']
    confirm = jsonData['today']['confirm']
    accu_confirm = jsonData['total']['confirm']
    dead = jsonData['total']['dead']
    deadRate = jsonData['total']['deadRate']
    heal = jsonData['total']['heal']
    healRate = jsonData['total']['healRate']
    jsonData_dict = {'名称': name, '新增确诊': confirm, '累积确诊': accu_confirm,
                     '死亡': dead, '死亡率': deadRate, '治愈': heal, '治愈率': healRate}
    return jsonData_dict


#  获取疫情数据
def getEpidemicData(jsonData):
    areaTree = jsonData['areaTree']
    for item in areaTree:
        if item['name'] == '中国':
            df_nCovData.loc[len(df_nCovData)] = getDataDic(item)
            item_1 = item['children']
            for item_2 in item_1:
                df_nCovData.loc[len(df_nCovData)] = getDataDic(item_2)
                item_3 = item_2['children']
                for item_4 in item_3:
                    df_nCovData.loc[len(df_nCovData)] = getDataDic(item_4)
    return df_nCovData


#  保存数据
def saveData(dataFrame, fileName, dirPath='./tempo/spider/epidemicData', ):
    createDir(dirPath)
    listTime = (fileName.split(' ')[1]).split(':')
    cur_fileName = fileName.split(
        ' ')[0] + ' ' + listTime[0] + '时' + listTime[1] + '分' + listTime[2] + '秒' + '.xlsx'
    if (os.path.exists(dirPath + '/' + cur_fileName)):
        print('数据已经存在！')
        processLabel['text'] = "数据已经存在！"

    else:
        dataFrame.to_excel(dirPath + '/' + cur_fileName)
        print('\n数据爬取完成！')
        processLabel['text'] = "数据爬取完成！"


#  创建文件夹
def createDir(dirPath):
    if not os.path.exists(dirPath):
        os.mkdir(dirPath)


#  爬取数据
def crawl_data():
    print('数据爬取开始！')
    processLabel.pack()

    # 打开网页
    jsonData = open_url()
    # 获取数据更新时间
    updataTime = getUpdataTime(jsonData)
    # 获取疫情数据，用pandas的数据框架保存
    dataFrame = getEpidemicData(jsonData)
    # 保存数据
    saveData(dataFrame, updataTime)


#  定时执行任务
def timeWork(interval=60 * 30):
    while True:
        crawl_data()
        print("开始定时爬取")
        root.iconify()  # 最小化窗口
        time.sleep(interval)


if __name__ == "__main__":
    open_win()
