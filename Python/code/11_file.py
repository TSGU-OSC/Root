"""
# 打开文件
# 选择写入模式,如果文件不存在会创建文件
# w 如果文件存在,会清空   a :追加写入
f=open('1.txt','a')
# 写入文件
f.write('Hello\n')

# 创建列表,包含一组姓名:循环获取每个姓名,将每个姓名写入到文件stu.txt中
names=['依依','柒柒','发发','猫猫','狗狗','杨杨']
# 打开文件
f=open('stu.txt','a')
# 循环获取每一个
for item in names:
    # print(item)
    # 将每一个姓名写入到文件
    f.write(item+'/n')

# 读取文件
f=open('stu.txt','r')
print(f.readline())
# 读取一行
print(f.readline())
print(f.readline())
print(f.readline())
# 读取所有的行
print(f.readlines())
"""


f=open('stu.txt','r')
lines=f.readlines()
print(lines)
for  item in lines:
    # 截取字符串
    print(item[0:-1])
    print(item)