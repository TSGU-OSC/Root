user=input('请输入用户名:')
code=input('请输入密码:')
if user=='admin' and code=='abc123':
    print('登录成功')
          


price=input('请输入商品的总价')
price=int(price)
if price>=300:
    price-=30
print(price)