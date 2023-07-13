b=input('请输入一个值')
b=int(b)
b1=True
b2=False
print(b>18)

scores=[89,79,99,78,100]
print(scores[1:4])

cities=['重庆','广西','福建','三亚','上海','浙江','北京']
c1=input('请输入一个城市:')
cities.append(c1)
c2=int(input('请提供下标'))
c2=int(c2)
del cities[c2]
print(cities)
