#引入模块，得到的是一个对象
import emp

# 获取模块对象打印
print(emp)
# 访问另一个模块的变量，要通过这个对象
print(emp.name)
# 访问另一个模块里面的函数
emp.say()
