import csv
# 设置新的一行开始的方式，默认会带回车换行
f=open('book.csv','w',newline='')
fieldnames=['id','bname','author','publish','pubtime','price','rate','num','desc']
data={
    'id':1,
    'bname':'红楼梦',
    'author':'曹雪芹',
    'publish':'人民文学出版社',
    'pubtime':'1996-12',
    'price':'59.70',
    'rate':'9.6',
    'num':'402474',
    'desc':'都云作者痴，谁解其中味'
}
# fieldnames  用于设置表头
writer=csv.DictWriter(f,fieldnames=fieldnames)
writer.writeheader()
writer.writerow(data)