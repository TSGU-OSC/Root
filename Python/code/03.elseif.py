
day=input('请输入星期几')
day=int(day)
if day==1:
    print('小笼包')
elif day==2:
    print('小笼包')
elif day==3:
    print('大闸蟹')
elif day==4:
    print('麻辣香锅')
elif day==5:
    print('小吊梨汤')
elif day==6:
    print('油焖虾')
elif day==7:
    print('新疆炒米粉')
else:
    print('川菜')
 


score=input('请输入一个成绩')
score=int(score)
if score>=90 and score <=100:
    print('优秀')
elif score>=80 and score <90:
    print('良好')
elif score>=70 and score<80:
    print('中等')
elif score>=60 and score<70:
    print('及格')
else:
    print('不及格')