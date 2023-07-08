# 编写08_douban.py,要求用户提供开始和结束的页码，抓取1-5之间的页面
import requests

import time
import random

# 引入随机生成用户代理的模块
from fake_useragent import UserAgent

# 随机生成用户代理
# print(UserAgent().random)


url='https://book.douban.com/top250?start={}'
headers={
    'User-Agent':'UserAgent().random'}
start=input('请输入开始的页码:')
end=input('请输入结束的页码:')
start=int(start)
end=int(end)
for item in range(start,end+1):
    #    print(item)
    # 通过当前的页码计算出需要的参数
       pn=(item-1)*25
    #    print(pn)
       r=requests.get(url=url.format(pn),headers=headers)
    #    print(r)
       f=open('douban/豆瓣读书top250_第{}页.html'.format(item),'w',encoding='utf-8')
       f.write(r.text)
       time.sleep(random.randint(1,3))

