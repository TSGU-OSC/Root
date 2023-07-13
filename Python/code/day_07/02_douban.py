"""
# 步骤：
1.引入模块
2.发送请求,获取HTML
3.解析HTML,通过xpath提取数据
4.将数据写入到csv文件
"""

# 使用Python爬虫抓取豆瓣读书第1页的数据（书名，概况，评分，简介）
# ，将抓取的数据写入搭配豆瓣读取csv
import requests
from fake_useragent import UserAgent
import csv
from lxml import etree

f=open('豆瓣读书.csv','w',newline='',encoding='utf-8')
fieldnames=['title','cont','rate','desc']
writer=csv.DictWriter(f,fieldnames=fieldnames)
writer.writeheader()

url='https://book.douban.com/top250'
headers={
    'User-Agent':'UserAgent().random'
}
r=requests.get(url=url,headers=headers)
print(r.text)

obj=etree.HTML(r.text)
print(obj)
list=obj.xpath('//table')
for item in list:
    # 去除两端空白字符串:s=s.strip()
    # .//：找子孙后代的标签    ./：找子代标签
    title=item.xpath('.//div[@class="pl2"]/a/text()')[0].strip()
    cont=item.xpath('.//p[@class="pl"]/text()')[0]
    rate=item.xpath('.//span[@class="rating_nums"]/text()')[0]
    arr=item.xpath('.//span[@class="inq"]/text()')
    # 判断长度
    if len(arr)==0:
      desc=''
    else:
      desc=arr[0]
    # print(title,cont,rate,desc)
    # print(item)
# 将这组值放入字典格式数据
    o={
    'title':title,
    'cont':cont,
    'rate':rate,
    'desc':desc
}
    print(o)
    writer.writerow(o)
