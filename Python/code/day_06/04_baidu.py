# 引入requests模块，用于发送请求
import requests


# 请求的网址（URL)
url='https://tieba.baidu.com/f?kw=蔡徐坤'


headers={
    # 设置用户代理（用户使用的浏览器）
    'User-Agent':'Mozilla/5.0(Windows;U;WindowsNT6.1;en-us)AppleWebKit/534.50(KHTML,likeGecko)Version/5.1Safari/534.50'
}

# 使用发送请求，

r=requests.get(url=url,headers=headers)
print(r)
# 获取网页的源代码（htmml结构）
# print(r.text)
# 将获取的源代码写入一个html文件（baidu.html)
# 设置为和网页一样的编码
f=open('baidu.html','w',encoding='utf-8')
f.write(r.text)