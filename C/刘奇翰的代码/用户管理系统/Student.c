#include "Student.h"
int main()
{
    welcome();
    Chain *head=malloc(sizeof(Chain));
    head->next=NULL;
    read(head);//从硬盘读取数据到内存
    while(1){
        printf("**请输入您选择的功能**\n");
        char c;
        scanf("%c",&c);
        getchar();//scanf会将回车读入缓冲区，getchar吸收回车
        switch(c)
        {
            case '1':
            input(head);break;
            case '2':
            output(head);break;
            case '3':
            found(head);break;
            case '4':
            delete(head);break;
            case '5':
            change(head);break;
            case '6':
            sort(head);break;
            case '7':
            exit(0);//令程序退出
            default :break;
        }
    }
    return 0;
}
 
void welcome()
{
    printf("**********************\n");
    printf("*欢迎来到学生管理系统*\n");
    printf("**输入1录入学生数据**\n");
    printf("**输入2打印学生数据**\n");
    printf("**输入3查找学生数据**\n");
    printf("**输入4删除学生数据**\n");
    printf("**输入5修改学生数据**\n");
    printf("**输入6排序学生数据**\n");
    printf("**输入7退出管理系统**\n");
}

void input(Chain *head)
{
    Chain *move=head,*fresh=malloc(sizeof(Chain));
    fresh->next=NULL;
    printf("Plz write num,name,score:\n");
    scanf("%d%s%d",&fresh->stu.num,fresh->stu.name,&fresh->stu.score);
    getchar();
    while(move->next!=NULL)
    {
        move=move->next;
    }
    move->next=fresh;
    save(head);//保存数据到硬盘
}

void output(Chain *head)
{
    Chain *move=head;
    move=move->next;
    while(move!=NULL)
    {
        printf("%-4d%-20s%4d\n",move->stu.num,move->stu.name,move->stu.score); 
        move=move->next;
    }
}

void save(Chain *head)
{
    FILE *fp;
    Chain *move=head;
    move=move->next;    
    if((fp=fopen("Stu.dat","w"))==NULL)
    {
        printf("cannot open file!");
        exit(0);
    }
    while(move!=NULL)
    {
        if(fwrite(&move->stu,sizeof(Chain),1,fp)!=1)
        {
            printf("file write error!");
            return;
        }
        move=move->next; 
    }
    fclose(fp);
}

void read(Chain *head)
{
    FILE *fp;
    Chain *move=head,*fresh=malloc(sizeof(Chain));
    fresh->next=NULL;
    if((fp=fopen("Stu.dat","r"))==NULL)
    {
        printf("cannot open file!");
        exit(0);
    }
    while(1)
    {
        if(fread(&fresh->stu,sizeof(Chain),1,fp)!=1)
        {
            printf("**reading complete!**\n");
            return;
        }
        move->next=fresh; 
        move=fresh;
        fresh=malloc(sizeof(Chain));
        fresh->next=NULL;
    }
}

void found(Chain *head)
{
    Chain *move=head;
    move=move->next;
    int n;
    printf("Plz write num:");
    scanf("%d",&n);
    getchar();
    while(1){
        if(move->stu.num==n){
            printf("%d\t%s\t%d\n",move->stu.num,move->stu.name,move->stu.score);
            break;
        }
        move=move->next;
        if(move==NULL){
            printf("There are no this one!\n");
            return;//令函数结束
        }
    }
}

void delete(Chain *head)
{
    Chain *move=head;
    move=move->next;
    int n;
    printf("Plz wirte the one's num which you want to delete!\n");
    scanf("%d",&n);
    getchar();
    while(1){
        if(move->next->stu.num==n){
            move->next=move->next->next;
            save(head);
            return;
        }
        move=move->next;
    }
}

void change(Chain *head)
{
    Chain *move=head;
    move=move->next;
    int n;
    printf("Plz write the one's num which you want to change!\n");
    scanf("%d",&n);
    getchar();
    while(1){
        if(move->stu.num==n){
            printf("Plz write num,name,score:\n");
            scanf("%d%s%d",&move->stu.num,move->stu.name,&move->stu.score);
            getchar();
            save(head);
            return;
        }
        move=move->next;
    }
}

void sort(Chain *head)
{
    Chain *t1,*t2,*fake=head;
    Chain *move=fake;
    int max;
    while(fake->next!=NULL){
        move=fake;
        move=move->next;
        max=move->stu.score;
        while(move->next!=NULL){
        if(max<move->next->stu.score){
            if(move->next->next==NULL){
                t1=fake->next;
                fake->next=move->next;
                move->next=NULL;
                fake->next->next=t1;
                break;
            }//特殊情况特殊处理（最后一位）
            t1=fake->next;t2=move->next->next;
            fake->next=move->next;
            fake->next->next=t1;
            move->next=t2;
        }//链表的交换
        move=move->next;
        }
        fake=fake->next;//把最大的排到第一个 链表头就后移 只比较链表头后面的数据
    }
    save(head);
}