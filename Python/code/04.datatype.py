phone = {
    'brand':'apple',
    'price':'6000',
    'color':'purple',
    'place':'北京',
    'time':'1998.06.14'
}
print(phone)


group={
    'group_name':'易燃易爆',
    'group_slogan':'学IT,有python,走遍天下都不怕',
    'group_menmber_number':'6',
    'group_number':'6'
}
print(group)


member={
    'number':'2514',
    'name':'jackson yi',
    'sex':'男',
    'birthday':'1998.10.21',
    'wage':'8000'
}
print(member['name'])
member['wage']=12000
member['department']='市场营销部'
del(member['birthday'])
print(member)

movie=[]
m1={
    'title':'怦然心动',
    'director':'玛德琳卡罗尔',
    'time':'2010-07-26',
    'place':'America',
    'rate':'9.1'
}
m2={
    'title':'让子弹飞',
    'director':'姜文',
    'time':'2010-12-16',
    'place':'中国大陆',
    'rate':'9.0'
}
movie.append(m1)
movie=[m1,m2]
print(movie)


human={
    'name':'jackson_yi',
    'sex':'男',
    'favor':['打篮球','弹吉他','跑步','玩游戏']
}
print(human)


names=['依依','柒柒','依依','柒柒','茉子茉']
print(set(names))
print(list(names))
