#include<stdio.h>
#include<stdlib.h>

//定义用户结构体
typedef struct _Student{
    int num;
    char name[20];
    int score;
}Student;

//再定义一个结构体方便使用链表
typedef struct _Chain{
    Student stu;
    struct _Chain *next;  
}Chain;

void welcome();//欢迎界面&功能介绍

void input(Chain *head);//键盘输入数据

void output(Chain *head);//打印数据

void save(Chain *head);//保存数据到硬盘

void read(Chain *head);//读取数据到内存

void found(Chain *head);//用学号（可以自定义）查找

void delete(Chain *head);//用学号（可以自定义）指定删除某一用户数据

void change(Chain *head);//用学号（可以自定义）指定修改某一用户数据

void sort(Chain *head);//按照成绩（可以自定义）排序