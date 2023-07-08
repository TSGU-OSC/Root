# 创建函数，传递数字，返回1~n总和
def getSum(a):
    i=1
    # 计算总和
    sum=0
    while i<=100:
        # i代表所有的整数
        # 将所有的整数加到sum
        sum+=i
        i+=1
        # 循环结束后，返回总和
    return sum

# 创建函数，传递数字，返回1~n乘积
def getSquare(s):
# 声明变量，用于保存乘积，初始值
    # 计算1~n乘积
    j=1
    area=1
    while j<=s:
        # j代表所有整数
        # 将所有的整数乘以到area
        area*=j
        j+=1
    return area
