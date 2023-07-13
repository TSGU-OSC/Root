
#   面向对象  编程   
# 类: class,
# 对象：数据
    # 定义一个学生类：用户名首字母大写：如：Student    class Student:
    # 类 = 变量 + 函数
class Student():
     # 使用类的时候，会自动调用函数
    def __init__(self,id,name,score):
      # def__init__(self):
      #   print('这个函数会被调用了')
      #   print(id,name,score)

      #通过self把传递的值添加到对象
      self.id=id
      self.name=name
      self.score=score

    #   要有其他的功能
    # 自我介绍
    def say(self):
      print('我的姓名叫：{} 我这次的成绩是{}').format(self.name,self.score)



    # 通过规定的类添加一条数据（实例化对象）
    # 会自动调用类中  __init__函数 
p1=Student(1,'张三',85)
print(p1)
# 获取对象中的值
print(p1.id,p1.name,p1.score)
# 调用方法
p1.say()

# 通过Student类创建第二个对象（第二个学生）
# p2:对象名
p2=Student(2,'周杰伦',90)
print(p2)
# . :代表“的”
print(p2.id,p2.name,p2.score)