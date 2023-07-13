# 引入请求模块
import requests

# 引入用户代理模块
from fake_useragent import UserAgent

# 引入csv模块
import csv

# 引入用于提取数据模块
from lxml import etree

# 以写入的方式打开csc文件
f=open('盗墓笔记.csv','w',newline='')
# 设置csv文件的表头（根据字典格式里面的数据，跟字典格式里面数据一样）
fieldnames=['title','desc']
# 创建写入者，以字典格式写入数据
writer=csv.DictWriter(f,fieldnames=fieldnames)
# 写入表头
writer.writeheader()
# 写入每一条字典数据


# 设置要抓取的网址
url='https://www.daomubiji.com'

# 设置请求头中用户代理，随机生成
headers={
    'User-Agent':'UserAgent().random'
}

# 请求网址，获取网页源代码（HTML结构）
r=requests.get(url=url,headers=headers)

# 输出打印网页源代码
# print(r.text)

# 将HTML结构解析为Element对象
obj=etree.HTML(r.text)
# 看是否被解析为ELement对象  出现<Element html at xxx>即为解析成功
# print(obj)

# 使用xpath提取数据
list=obj.xpath('//div[@class="homebook"]')
# print(list)

# 循环这一组Element对象，获取每一个Element对象（每本书）
for item in list:
    # print(item)
    # 再一次使用xpath,查找每本书的标题和简介
    title=item.xpath('./h2/text()')[0]
    desc=item.xpath('./p/text()')[0]
    # 看是否得到每一本书的标题和简介
    print(title,desc)

# 将标题和简介放入到字典格式的数据，才可以往csv文件中写入
o={
    'title':title,
    'desc':desc
}
# 打印输出o是否成功，即标题和简介是否成功放入到字典格式的数据
# print(o)
writer.writerow(o)


# 使用Python爬虫抓取豆瓣读书第1页的数据（书名，概况，评分，简介）
# ，将抓取的数据写入搭配豆瓣读取csv
