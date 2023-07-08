import requests
from fake_useragent import UserAgent
import csv
from lxml import etree
import time
import random
url='https://www.jeebei.com/pingce/'
headers={
    'User-Agent':UserAgent().random
}
r=requests.get(url=url,headers=headers)
r.encoding='utf-8'
print(r.text)
obj=etree.HTML(r.text)
list=obj.xpat('.//div[@class=""]')