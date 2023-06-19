#include<iostream>
#include<conio.h>
#include<string.h>
#include<Windows.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct _Student
{
	char name[20];//姓名
	char sex;//性别
	int age;//年龄
	int stuNum;//学号
	int score;//成绩
}Student;
//链表
typedef struct _Node
{
	Student stu;//学生
	struct _Node* pNext;//指向下一个节点的指针

}Node;
Node *g_pHead = NULL;
//查找信息
Node* LookForStu()
{
	int nStuNum;
	char szName[20];
	std::cout << "Please input the number whose you search for:" << std::endl;
	std::cin >> nStuNum;
	std::cout << "Please input the name whose you search for:" << std::endl;
	std::cin >> szName;
	Node* p = g_pHead;
	while (p!=NULL)
	{
		//字符串比较函数strcmp
		if (p->stu.stuNum==nStuNum||0==strcmp(p->stu.name,szName))
		{
			return p;
		}
		p = p->pNext;
	}
	//查询不到返回空值
	return NULL;
}
void InitialPage();
//录入信息
void InputStudent();
//打印信息
void PrintStudent();
//保存信息
void SaveStudent();
//读取信息
void ReadStudent();
//统计人数
int CountStudent();
//查找信息
void LookForStudent();
//修改信息
void ModifyStudent();
//删除信息
void RemoveStudent();