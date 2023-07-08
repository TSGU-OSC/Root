import requests
from fake_useragent import UserAgent
import csv
from lxml import etree
import time
import random

f=open('达内慕课网.csv','w',newline='',encoding='utf-8')
fieldnames=['name','num']
writer=csv.DictWriter(f,fieldnames=fieldnames)
writer.writeheader()
url='https://www.tmooc.cn/free/'
headers={
    'User-Agent':UserAgent().random
}
r=requests.get(url=url,headers=headers)
# 将获取HTML编码转为utf-8
r.encoding='utf-8'
print(r.text)

obj=etree.HTML(r.text)
# print(obj)
list=obj.xpath('//li[@class="pic-box pull-left free"]')
# print(list)
for item in list:
  name=item.xpath('.//h4/a/text()')[0].strip()
  num=item.xpath('.//span[@class="sign-num pull-right color-888"]/text()')[0][0:-3]
    # print(item)
    
    # 查找图片
  pic=item.xpath('.//img/@data-original')[0]
    #获取文件名称
  filename=pic.split('///')[-1]
  print(filename)

    #继续请求抓取图片
  r2=requests.get(pic)
    # 把图片的内容写入另一个文件下（以二进制写入的方式打开文件）
  f2=open('img/'+filename,'wb')
    # 写入图片数据
  f2.write(r2.content)

  o={
        'name':name,
        'num':num
    }
  print(o)
  writer.writerow(o)
    # 随机停顿1~3秒
  time.sleep(random.randint(1,3))