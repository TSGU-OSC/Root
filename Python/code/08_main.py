# import 模块 ：引入模块中所有的，得到的是一个模块对象
import pack.user as u
print(u.username,u.tel,u.email)

# 按需引入 from m模块 import xxx,xx 只能使用引入的
from pack.user import username,tel,email
print(username,tel,email)
# \n  :换行符
print('用户名：{} \n手机:{} \n邮箱:{} \n'.format(username,tel,email))


# 自定义模块（用户创建），核心模块（python官方提供的模块，第三方模块（一些组织或者个人发布的模块）
