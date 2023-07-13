import requests
url='https://www.daomubiji.com/'
headers={
    'User-Agent':'Mozilla/5.0(Windows;U;WindowsNT6.1;en-us)AppleWebKit/534.50(KHTML,likeGecko)Version/5.1Safari/534.50'
}
r=requests.get(url=url,headers=headers)
print(r)
# print(r.text)
f=open('daomubiji.html','w',encoding='utf-8')
f.write(r.text)