
# 创建函数，计算出任意两个数字相加的和
def add(a,b):
  # 函数体：要重复执行的代码
  print(a+b)
# 调用：执行函数体中的代码
# add(2,3)
# 把函数调用后的得到的结果保存下来
num=add(4,7)
print(num)


# 创建函数getSUm，传递任意一个数字，返回（return)出1~任意数字之间的所有整数的和
def getSum(a):
  # 函数体：计算1~a之间所有整数的和
    i=1
    sum=0
    while i<=a:
      # i代表中间所有整数
      # 求和
      sum+=i
      i+=1
    return sum
num=getSum(50)
num=str(num)
print('循环的结果'+num)

