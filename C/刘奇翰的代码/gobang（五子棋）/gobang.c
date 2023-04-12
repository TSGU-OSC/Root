#include "gobang.h"
#include<stdio.h>

void settinginfo();//欢迎界面

int setting();//功能选择

void exe();//主程序

void black();//黑方下棋

void white();//白方下棋

int gobang_exe();//判断输赢

int gobang_judgement();//检查是否和棋

void gobang_print();//打印棋局

int gobang[15][15]={0};//初始化棋盘

void settinginfo()
{
    printf("****欢迎试玩五子棋****\n");
    printf("****输入1继续游戏****\n");
    printf("****输入2退出游戏****\n");
    printf("**********************\n");
    printf("****输入坐标来下棋****\n");
    printf("******示例如下：******\n");
    printf("0 0\n");
    printf("**********************\n");
}

int setting()
{
    int tem;   
    scanf("%d",&tem);
    getchar();
    switch(tem)
    {
        case 1:exe();
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<15;j++)
            {
                gobang[i][j]=0;
            }
        }
        return 0;
        case 2:printf("exit successful!\n");return 1;
        default : printf("error!\n");return 0;
    };
}

int gobang_exe()
{
    int x=0,y=0,i=0,j=0,m=0,n=0;
    for(x=0,y=0;x<15;x++)
    {
        for(i=x,j=y;j<15;j++)
        {
            if(gobang[i][j]==1) { m++; }
            if(gobang[i][j]==2) { n++; }
            if(j>0)
            {
                if(gobang[i][j]!=gobang[i][j-1])
                {
                    if(gobang[i][j]==1) { m=1; }
                    if(gobang[i][j]==2) { n=1; }
                }
            }
            if(m>4) { return 1; }
            if(n>4) { return 2; }
        }
        m=0;n=0;
        if(x>3)
        {
            for(i=x,j=y;i>=0&&j<15;i--,j++)
            {
                if(gobang[i][j]==1) { m++; }
                if(gobang[i][j]==2) { n++; }
                if(j>0)
                {
                    if(gobang[i][j]!=gobang[i+1][j-1])
                    {
                        if(gobang[i][j]==1) { m=1; }
                        if(gobang[i][j]==2) { n=1; }
                    }
                }
                if(m>4) { return 1; }
                if(n>4) { return 2; }
            }
        }
        m=0;n=0;
        if(x<11)
        {
            for(i=x,j=y;i<15&&j<15;i++,j++)
            {
                if(gobang[i][j]==1) { m++; }
                if(gobang[i][j]==2) { n++; }
                if(j>0)
                {
                    if(gobang[i][j]!=gobang[i-1][j-1])
                    {
                        if(gobang[i][j]==1) { m=1; }
                        if(gobang[i][j]==2) { n=1; }
                    }
                }
                if(m>4) { return 1; }
                if(n>4) { return 2; }
            }
        }
        m=0;n=0;
    }
    for(x=0,y=0;y<15;y++)
    {
        for(i=x,j=y;i<15;i++)
        {
            if(gobang[i][j]==1) { m++; }
            if(gobang[i][j]==2) { n++; }
            if(j>0)
            {
                if(gobang[i][j]!=gobang[i-1][j])
                {
                    if(gobang[i][j]==1) { m=1; }
                    if(gobang[i][j]==2) { n=1; }
                }
            }
            if(m>4) { return 1; }
            if(n>4) { return 2; }
        }
        m=0;n=0;
        if(y<11)
        {
            for(i=x,j=y;i<15&&j<15;i++,j++)
            {
                if(gobang[i][j]==1) { m++; }
                if(gobang[i][j]==2) { n++; }
                if(j>0)
                {
                    if(gobang[i][j]!=gobang[i-1][j-1])
                    {
                        if(gobang[i][j]==1) { m=1; }
                        if(gobang[i][j]==2) { n=1; }
                    }
                }
                if(m>4) { return 1; }
                if(n>4) { return 2; }
            }
        }
        m=0;n=0;
    }
    for(x=14,y=0;y<11;y++)
    {
        for(i=x,j=y;i>=0&&j<15;i--,j++)
            {
                if(gobang[i][j]==1) { m++; }
                if(gobang[i][j]==2) { n++; }
                if(j>0)
                {
                    if(gobang[i][j]!=gobang[i+1][j-1])
                    {
                        if(gobang[i][j]==1) { m=1; }
                        if(gobang[i][j]==2) { n=1; }
                    }
                }
                if(m>4) { return 1; }
                if(n>4) { return 2; }
            }
            m=0;n=0;
    }
    return 0;
}

int gobang_judgement()
{
    int b=0,i=0,j=0;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(gobang[i][j]!=0)
            {
                b++;
            }
        }    
    }
    if(b==225)
    {
        printf("stalemate!\n");
        return 3;
    }
}

void exe()
{
    int temporary=0;
    do{
        black();
        gobang_print();
        temporary=gobang_exe();
        if(temporary==1||temporary==2) { break; }
        temporary=gobang_judgement();
        if(temporary==3) { return; }

        white();
        gobang_print();
        temporary=gobang_exe();
        if(temporary==1||temporary==2) { break; }
        temporary=gobang_judgement();
        if(temporary==3) { return; }   
    }while(temporary!=1&&temporary!=2&&temporary!=3);

    if(temporary==1) { printf("black win!\n"); }
    if(temporary==2) { printf("white win!\n"); }
}

void black()
{
    int i=0,j=0;
    printf("plz black write:\n");
    scanf("%d %d",&i,&j);
    for(int t=0;t<5;t++)
    {
        if(gobang[i][j]==0&&i<15&&i>=0&&j<15&&j>=0) 
        {
            gobang[i][j]=1;
            return;
        }
        else 
        {
            printf("error!plz black write again:\n");
            scanf("%d %d",&i,&j);
        }
    }
}

void white()
{
    int i=0,j=0;
    printf("plz white write:\n");
    scanf("%d %d",&i,&j);
    for(int t=0;t<5;t++)
    {
        if(gobang[i][j]==0&&i<15&&i>=0&&j<15&&j>=0) 
        {
            gobang[i][j]=2;
            return;
        }
        else 
        {
            printf("error!plz white write again:\n");
            scanf("%d %d",&i,&j);
        }
    }
}

void gobang_print()
{
    int i=0,j=0;
    printf("      ");
    for(j=0;j<15;j++)
    {
        
        if(j>8)
        {
             printf("%d  ",j);
            if(j==14)
            {
                printf("\n\n\n");
            }
        }
        else
        {
            printf("%d   ",j);
        }
    }
    for(i=0;i<15;i++)
    {
        if(i<10)
        {
            printf("%d     ",i);
        }
        if(i>=10)
        {
            printf("%d    ",i);
        }
        for(j=0;j<15;j++)
        {       
            printf("%d   ",gobang[i][j]);
            if(j==14)
            {
                printf("\n\n");
            }
        }    
    }
}

int main()
{
    int returnvalue;
    do
    {
       gobang_print();
       settinginfo();
       returnvalue=setting(); 
    } 
    while(returnvalue!=1);
    return 0;
}

