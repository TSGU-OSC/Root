
# 创建函数，计算任意两个数字相加的和
def add(a,b):      # add:函数名称，可以自定义    a,b:用于接收外部传递的值（即传参）
     
    print(a+b)     # 函数体：计算任意两个数字相加  

#调用：传递两个数字 (传递参数)
add(1,2)
add(3,4) 


# 创建函数getSum,传递任意一个数字，计算出1~任意数字之间的所有整数的和
def getSum(a):
    # 计算1~a之间所有整数的和
    i=1
    sum=0
    while i<=a:
        sum+=i
        i+=1
    print(sum)     # 打印输出总和
# 调用
getSum(500)



# 创建函数getCount,任意传递两个年份，返回两个闰年的数量
def getCount(a,b):
#    获取a~b之间所有的闰年的数量
        i=a
        # i代表所有的年份
        count=0
        while i<=b:
             if i%400==0 or i%4==0 and i%100!=0:
                    count+=1

             i+=1
            #  打印闰年数量
        print(count)
getCount(2000,2400)

    
