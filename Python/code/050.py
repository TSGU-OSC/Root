# 按需引入   xxx as xx:  xxx起别名为xx
# 从emp.py模块中引入name  sex
from emp import name as n,sex as s
print(n,s)

# 按需引入所有的
from emp import *
print(salary)
say()