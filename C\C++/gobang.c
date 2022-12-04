#include<stdio.h>
#include<math.h>
int main()
{
    int gobang(int x[][15],int i,int j);
    int a[15][15],i,j,y,b;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            a[i][j]=0;
        }    
    }
    while(1){
    printf("plz black write:\n");
    scanf("%d %d",&i,&j);
    a[i][j]=1;
    printf("    ");
    for(j=0;j<9;j++)
    {
        printf("%d   ",j);
    }
    for(j=9;j<15;j++)
    {
        printf("%d  ",j);
        if(j==14)
        {
            printf("\n\n");
        }
    }
    for(i=0;i<15;i++)
    {
        if(i<10)
        {
            printf("%d   ",i);
        }
        if(i>=10)
        {
            printf("%d  ",i);
        }
        for(j=0;j<15;j++)
        {       
            printf("%d   ",a[i][j]);
            if(j==14)
            {
                printf("\n\n");
            }
        }    
    }
    y=gobang(a,i,j);
    if(y==1)
    {
        break;
    }
    b=0;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(a[i][j]!=0)
            {
                b++;
            }
        }    
    }
    if(b==225)
    {
        printf("stalemate!\n");
        break;
    }
    printf("plz white write:\n");
    scanf("%d %d",&i,&j);
    a[i][j]=2;
   printf("    ");
    for(j=0;j<9;j++)
    {
        printf("%d   ",j);
    }
    for(j=9;j<15;j++)
    {
        printf("%d  ",j);
        if(j==14)
        {
            printf("\n\n");
        }
    }
    for(i=0;i<15;i++)
    {
        if(i<10)
        {
            printf("%d   ",i);
        }
        if(i>=10)
        {
            printf("%d  ",i);
        }
        for(j=0;j<15;j++)
        {       
            printf("%d   ",a[i][j]);
            if(j==14)
            {
                printf("\n\n");
            }
        }    
    }
    
    y=gobang(a,i,j);
    if(y==1)
    {
        break;
    }
    b=0;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(a[i][j]!=0)
            {
                b++;
            }
        }    
    }
    if(b==225)
    {
        printf("stalemate!\n");
        break;
    }
    }
}
int gobang(int x[][15],int i,int j)
{
    int z=0;
    for(int q=0,w=0;q<15&&w<15;q++){
    i=q;
    j=w;
    for(int m=0,n=0;j<15;j++)
    {
        if(x[i][j]==1)
        {
            m++;
        }
        if(x[i][j]==2)
        {
            n++;
        }
        if(j>0)
        {
            if(x[i][j]!=x[i][j-1])
            {
                if(x[i][j]==1)
                {
                    m=1;
                }
                if(x[i][j]==2)
                {
                    n=1;
                }
            }
        }
        if(m>=5)
        {
            printf("black win\n");
            z=1;
            break;
        }
        if(n>=5)
        {
            printf("white win\n");
            z=1;
            break;
        }
    }
    i=q;
    j=w;
    for(int m=0,n=0;i<15;i++)
    {
        if(x[i][j]==1)
        {
            m++;
        }
        if(x[i][j]==2)
        {
            n++;
        }
        if(i>0)
        {
            if(x[i][j]!=x[i-1][j])
            {
                if(x[i][j]==1)
                {
                    m=1;
                }
                if(x[i][j]==2)
                {
                    n=1;
                }
            }
        }
        if(m>=5)
        {
            printf("black win\n");
            z=1;
            break;
        }
        if(n>=5)
        {
            printf("white win\n");
            z=1;
            break;
        }
    }
    i=q;
    j=w;
    for(int m=0,n=0;i<15&&j<15;i++,j++)
    {
        if(x[i][j]==1)
        {
            m++;
        }
        if(x[i][j]==2)
        {
            n++;
        }
        if(i>0&&j>0)
        {
            if(x[i][j]!=x[i-1][j-1])
            {
                if(x[i][j]==1)
                {
                    m=1;
                }
                if(x[i][j]==2)
                {
                    n=1;
                }
            }
        }
        if(m>=5)
        {
            printf("black win\n");
            z=1;
            break;
        }
        if(n>=5)
        {
            printf("white win\n");
            z=1;
            break;
        }
    }
    i=q;
    j=w;
    for(int m=0,n=0;i<15&&j<15&i>=0;i--,j++)
    {
       if(x[i][j]==1)
        {
            m++;
        }
        if(x[i][j]==2)
        {
            n++;
        }
         if(i>=4)
        {
            if(x[i][j]!=x[i+1][j-1])
            {
                if(x[i][j]==1)
                {
                    m=1;
                }
                if(x[i][j]==2)
                {
                    n=1;
                }
            }
        }
        if(m>=5)
        {
            printf("black win\n");
            z=1;
            break;
        }
        if(n>=5)
        {
            printf("white win\n");
            z=1;
            break;
        }
    }
    if(z==1)
    {
        break;
    }
    }
    for(int q=0,w=1;q<15&&w<15;w++)
    {
        i=q;
        j=w;
        for(int m=0,n=0;i<15;i++)
        {
            if(x[i][j]==1)
            {
                m++;
            }
            if(x[i][j]==2)
            {
                n++;
            }
            if(i>0)
            {
                if(x[i][j]!=x[i-1][j])
                {
                    if(x[i][j]==1)
                    {
                        m=1;
                    }
                if(x[i][j]==2)
                {
                    n=1;
                }
                }
            }
            if(m>=5)
            {
                printf("black win\n");
                z=1;
                break;
            }
            if(n>=5)
            {
                printf("white win\n");
                z=1;
                break;
            }
        }
        i=q;
        j=w;
        for(int m=0,n=0;i<15&&j<15;i++,j++)
        {
            if(x[i][j]==1)
            {
                m++;
            }
            if(x[i][j]==2)
            {
                n++;
            }
            if(i>0&&j>0)
            {
                if(x[i][j]!=x[i-1][j-1])
                {
                    if(x[i][j]==1)
                    {
                        m=1;
                    }
                    if(x[i][j]==2)
                    {
                        n=1;
                    }
                }
            }
            if(m>=5)
            {
                printf("black win\n");
                z=1;
                break;
            }
            if(n>=5)
            {
                printf("white win\n");
                z=1;
                break;
            }
        }
        if(z==1)
        {
            break;
        }
    }
    return z;
}