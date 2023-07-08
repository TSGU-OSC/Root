# 引入请求模块
import requests
# 要求用户提供吧主的关键字
words=input('请输入吧主的关键字:')
url='https://tieba.baidu.com/f?kw='+words
# 设置请求头中，用户使用的浏览器
headers={
    'User-Agent':'Mozilla/5.0(Windows;U;WindowsNT6.1;en-us)AppleWebKit/534.50(KHTML,likeGecko)Version/5.1Safari/534.50'
}
# 发送请求
r=requests.get(url=url,headers=headers)
print(r)
# 将获取的网页源代码写入到一个文件
f=open('{}吧.html'.format(words),'w',encoding='utf-8')
f.write(r.text)

