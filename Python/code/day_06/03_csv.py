
# 使用csv模块将一组音乐的数据写入到文件music.csv，
# 所有的音乐是一个列表的形式，
# 每条音乐包含的属性有编号，歌曲名称，歌手，时长


import csv
f=open('music.csv','w',newline='')
fieldnames=['id','song_name','singer','len']
music=[{'id': '1','song_name': '向云端','singer': '罗严','len': '03:28'},
        {'id': '2','song_name': '听悲伤的情歌','singer': '苏星婕','len': '03:18',},
        {'id': '3','song_name': 'Summer Summer','singer': 'AK刘彰','len': '02:50',},
        {'id': '4','song_name': '一般的一天(live)','singer': 'Wiz_H张子豪','len': '03:16',}]
#  print(music)
writer=csv.DictWriter(f,fieldnames=fieldnames)
writer.writeheader()

# 获取每一首音乐
for item in music:
#   print(item)
  writer.writerow(item)
