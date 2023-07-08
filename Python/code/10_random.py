"""
# 引入一个随机数模块
import random

# 获取随机数  random:0~1之间的小数  
print(random.random())
print(random.random())
print(random.random())


# randint:随机整数
print(random.randint(10,20))
print(random.randint(10,20))
print(random.randint(10,20))
"""

# 双色球  
# 红球：随机获取6个1~33之间的整数,不能重复
# 蓝球：随机获取1个1~16之间的整数，可以和之前的红球重复
# 将获取这组数字放入到列表中[]
import random
# 创建列表，保存获取的随机数
ball=[]
# 什么时候获取到6个不重复的，什么时候就结束
while True:
    n=random.randint(1,33)
    # 判断列表中是否含有当前获取的随机
    if n in ball:
# 如果存在,什么也不操作
     pass
# 否则不存在,将这个数字放入列表
    else:
       ball.append(n)
    #    判断是否为6个,如果是结束循环
    if len(ball)==6:
     break
print(ball)


ball.append(random.randint(1,16))
print(ball)