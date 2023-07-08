age=input('请输入年龄')
age=int(age)
if age>=18:
    print('成年人')
else:
    print('未成年人')


num=input('请输入数字：')
num=int (num)
if num%2==0:
    print('偶数')
else:
    print('奇数')


year=input('请输入一个年份')
year=int(year)
if year%400==0 or  year%4==0 and year%100!=0:
    print('闰年')
else:
    print('平年')