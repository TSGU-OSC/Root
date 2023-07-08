# 用户提供  开始的值，结束的值；可以抓取一组数据
# 抓取多页数据
# 引入模块
import requests

import time
import random

# 设置请求的网址，要准备拼接吧主的关键字和pn的值
url='https://tieba.baidu.com/f?kw={}&pn={}'

# 设置请求头，用户代理
headers={
    'User-Agent':'Mozilla/5.0(Windows;U;WindowsNT6.1;en-us)AppleWebKit/534.50(KHTML,likeGecko)Version/5.1Safari/534.50'
}


# 要求用户提供吧主的姓名，开始的页码，结束的页码
name=input('请输入吧主关键字:')
start=input('请输入开始的页码:')
end=input('请输入结束的页码:')

# 将输入的数字转换为整型
start=int(start)
end=int(end)
for item in range(start,end+1):
    # print(item)
    # 通过当前页码获取pn的值
    pn=(item-1)*50
    # print(pn)

    # 请求这一页的数据
    r=requests.get(url=url.format(name,pn))
    # print(r)
    # 将获取的源代码放入到指定文件夹里面去
    f=open('files/{}吧_第{}页.html'.format(name,item),'w',encoding='utf-8')
    f.write(r.text)

    # 抓取一次，停顿1~3秒钟
    time.sleep(random.randint(1,3))
    

"""
# 获取两者之间所有的整数  range:范围
# 产生1~n之间的所有整数
print(range(1,10))

# 通过for-in循环获取range之间所有的整数  range():不包含右范围
for item in range(1,11):
    print(item)
print(name,start,end)
"""