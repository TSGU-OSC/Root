# 创建一个员工类Emp 姓名：刘德华 ； 工资：50000 ；部门：演艺部
# 添加方法，实现自我介绍 
class Emp():
    def __init__(self,name,salary,apartment):
      self.name=name
      self.salary=salary
      self.apartment=apartment
      
    def say(self):
       print('我的姓名叫：{} 我的工资是：{} 我的部门是：{}'.format(self.name,self.salary,self.apartment))
    
    def __str__(self):
       return f"姓名：{self.name} 工资：{self.salary} 部门：{self.apartment}"
    
p1=Emp('刘德华',50000,'演艺部')   
print(p1)
print(p1.name,p1.salary,p1.apartment)
p1.say()

