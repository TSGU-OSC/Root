#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[100][100]={};
    for(int i=0;i<n;i++)
    {
        a[i][0]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>0&&j>0)
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
            if(j<=i)
            {
                printf("%6d",a[i][j]);
            }
            if(j==i)
            {
                printf("\n");
            }
        }
    }
}