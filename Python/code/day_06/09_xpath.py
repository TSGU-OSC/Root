# 引入请求模块
import requests
# 用于随机生成请求头
from fake_useragent import UserAgent

# 从lxml模块中引入方法，用于解析html
from lxml import etree

import csv

# 设置请求头中，用户代理
url='https://www.daomubiji.com/'
# 请求请求头中，用户代理
headers= {
    'User-Agent':UserAgent().random
}

# 发送请求
r=requests.get(url=url,headers=headers)
# 获取网页的源代码（就是一个html文件）
html=r.text
# print(html)

# 将html解析为Element对象
obj=etree.HTML(html)
print(obj)

#  使用  xpath  从html中提取出需要的数据
list=obj.xpath('//div[@class="homebook"]/h2')
# print(list)

# 通过循环获取到每一个
for item in list:
    # 具体获取标签h2的文本
    print(item.xpath('./text()')[0])

# 通过xpath获取每本书的简介部分
list1=obj.xpath('//div[@class="homebook"]/p/text()')

print(list1)
# 循环列表即可
for item in list:
    print(item)
