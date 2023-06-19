#include"StudentManageSystem.h"

void InitialPage()
{
	
	std::cout << "**************************************************" << std::endl;
	std::cout << "**\tWelcome to Student Manage System\t**" << std::endl;
	std::cout << "**************************************************" << std::endl;
	std::cout << "**\tPlease select the function\t\t**" << std::endl;
	std::cout << "**************************************************" << std::endl;
	std::cout << "**\t\t1、Input information\t\t**" << std::endl;
	std::cout << "**\t\t2、Print information\t\t**" << std::endl;
	std::cout << "**\t\t3、Save  information\t\t**" << std::endl;
	std::cout << "**\t\t4、Read  information\t\t**" << std::endl;
	std::cout << "**\t\t5、Count    heads\t\t**" << std::endl;
	std::cout << "**\t\t6、Look for information\t\t**" << std::endl;
	std::cout << "**\t\t7、Modify information\t\t**" << std::endl;
	std::cout << "**\t\t8、Remove information\t\t**" << std::endl;
	std::cout << "**\t\t0、Exit\t\t\t\t**" << std::endl;
	std::cout << "**************************************************" << std::endl;
}
void InputStudent()
{
	//创建新节点
	Node* pNewNode=(Node*)malloc(sizeof(Node));
	
	pNewNode->pNext = NULL;
	//头插法、尾插法
	//头插法
	if (g_pHead == NULL)
	{
		g_pHead = pNewNode;
	}
	else
	{
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}
	std::cout << "Please input student's name: " << std::endl;
	std::cin >> pNewNode->stu.name;//从键盘输入学生姓名
	std::cout << "Please input student's age:" << std::endl;
	std::cin >> pNewNode->stu.age;//键盘输入学生年龄
	std::cout << "Please input student's number:" << std::endl;
	std::cin >> pNewNode->stu.stuNum;//键盘输入学生学号
	std::cout << "Please input student's sex:" << std::endl;
	std::cin >> pNewNode->stu.sex;//键盘输入学生性别
	std::cout << "Please input student's score:" << std::endl;
	std::cin >> pNewNode->stu.score;//键盘输入学生成绩
	std::cout << "Input successfully!" << std::endl;
	system("pause");//暂停
	system("cls");//清屏

}
void PrintStudent()
{
	system("cls");
	std::cout << "***************************************************" << std::endl;
	std::cout << "**\tWelcome to Student Manage System\t **" << std::endl;
	std::cout << "***************************************************" << std::endl;
	std::cout << "*Number\t*Name\t*Age\t*Sex\t*Score\t\t  *" << std::endl;
	std::cout << "***************************************************" << std::endl;
	//遍历链表
	Node* p = g_pHead;
	while (p != NULL)
	{
	
		std::cout << "*" << p->stu.stuNum << "\t*" << p->stu.name << "\t*" << p->stu.age << "\t*" << p->stu.sex << "\t*" << p->stu.score << "\t\t  *" << std::endl;
		p = p->pNext;
	}
	std::cout << "***************************************************" << std::endl;
	system("pause");
	system("cls");
}
void SaveStudent()
{
	//打开创建文件
	FILE* fp;
	fopen_s(&fp,"stuinfo.data", "w");
	if (fp == NULL)
	{
		std::cout << "Failed to open file!" << std::endl;
		return;
	}
	//遍历链表
	Node* p = g_pHead;
	while (p != NULL)
	{
		fwrite(&p->stu,1,sizeof(Student),fp);
		p = p->pNext;
	}
	//关闭文件
	fclose(fp);
	std::cout << std::endl << "Data save successfully!" << std::endl;
	system("pause");
	system("cls");
}
void ReadStudent()
{
	FILE* fp;
	//打开文件
	fopen_s(&fp,"stuinfo.data", "r");
	if (fp == NULL)
	{
		std::cout << "Failed to open file!" << std::endl;
		return;
	}
	Student stu;
	while (fread(&stu, 1, sizeof(Student), fp))
	{
		//创建新节点
		Node* pNewNode=(Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;
		memcpy(pNewNode, &stu, sizeof(Student));
		//头插法
		if (g_pHead == NULL)
		{
			g_pHead = pNewNode;
		}
		else
		{
			pNewNode->pNext = g_pHead;
			g_pHead = pNewNode;
		}
	}
	fclose(fp);
	std::cout << "Loading data succeeded!" << std::endl;
	system("pause");
	system("cls");
}
int CountStudent()
{
	int nCount = 0;//学生总数
	//遍历链表
	Node* p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;
	}
	return nCount;
}
	

void LookForStudent()
{
	Node*p= LookForStu();
	if (p != NULL)
	{
		std::cout << "***************************************************" << std::endl;
		std::cout << "*Number\t*Name\t*Age\t*Sex\t*Score\t\t  *" << std::endl;
		std::cout << "***************************************************" << std::endl;
		std::cout << "*" << p->stu.stuNum << "\t*" << p->stu.name << "\t*" << p->stu.age << "\t*" << p->stu.sex << "\t*" << p->stu.score << "\t\t  *" << std::endl;
		std::cout << "***************************************************" << std::endl;
	}
	else
		std::cout << "Falied to search the student!" << std::endl;
	system("pause");
	system("cls");
}
void ModifyStudent()
{
	int nStuNum;
	std::cout << "Please input the number whose you need to modify:" << std::endl;
	std::cin >> nStuNum;
	Node* p = g_pHead;
	while (p != NULL)
	{
		//字符串比较函数strcmp
		if (p->stu.stuNum == nStuNum)
		{
			std::cout << "Please input the information what you need to modify:" << std::endl;
			std::cin >> p->stu.name>>p->stu.age>>p->stu.sex>>p->stu.score;
			std::cout << "Modify successfully!" << std::endl;
			break;
		}
		p = p->pNext;
	}
	if (p == NULL)
	{
		std::cout << "Falied to search the student!" << std::endl;
	}
	system("pause");
	system("cls");
}
void RemoveStudent()
{
	int nStuNum;
	std::cout << "Please input the number whose you want to delete:" << std::endl;
	std::cin >> nStuNum;
	Node* p1,*p2;
	//判断是否为头节点
	if (g_pHead->stu.stuNum == nStuNum)
	{
		p1 = g_pHead->pNext;
		free(p1);
		system("pause");
		system("cls");
		return;
	}

	Node* p = g_pHead;
	while (p->pNext!=NULL)
		{
			if (p->pNext->stu.stuNum == nStuNum)
			{
				p2 = p->pNext;
				p->pNext = p->pNext->pNext;
				free(p2);
				return;
			}
			p = p->pNext;
			if (p->pNext == NULL)
			{
				break;
			}
		}
	if (p->pNext == NULL)
	{
		std::cout << "Failed to search the student!" << std::endl;
	}
	
}
int main()
{
	while (1)
	{
		InitialPage();
		char ch=_getch();
		switch (ch)
		{
		case'1':
			InputStudent();//录入信息
			break;
		case'2':
			PrintStudent();//打印信息
			break;
		case'3':
			SaveStudent();//保存信息
			break;
		case'4':
			ReadStudent();//读取信息
			break;
		case'5':
			std::cout << "The total number of student is:" << CountStudent() << std::endl;//统计人数
			system("pause");
			system("cls");
			break;
		case'6':
			LookForStudent();//查找信息
			break;
		case'7':
			ModifyStudent();//修改信息
			break;
		case'8':
			RemoveStudent();//删除信息
			break;
		case'0':
			std::cout << "Bye bye!" << std::endl;
			Sleep(1000);
			exit(0);//退出系统
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}