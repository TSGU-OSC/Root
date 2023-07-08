
# 引入csv模块
import csv

# 以写入的方式打开1.csv文件，如果文件不存在会自动创建
f=open('1.csv','w')

# 定义csv文件的表头  （以列表的方式）
fieldnames=['id','name','sex']

# 写入的数据以  字典  的形式
data={
    'id':1,
    'name':'张三',
    'sex':'男'
}

# 选择以字典的方式写入数据,同时选择定义好的表头  writer:写入者
writer=csv.DictWriter(f,fieldnames=fieldnames)

# 写入表头
writer.writeheader()

# 写入数据
writer.writerow(data)


