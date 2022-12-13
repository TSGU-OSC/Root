#include<stdio.h>
void set(int a[100][100],int m);
void found(int a[100][100],int n);
int main()
{
	int a[100][100]={};
	int (*p)[100];
	int m=0,n=0;
	scanf("%d %d",&m,&n);
	p=a;
	set(p,m);
	found(p,n);
	return 0;
}
void set(int a[100][100],int m)
{
	int b=0,x=0,y=0,j=0,z=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&b);
		if(i==0)
		{
			a[0][0]=x;
			a[0][1]=b;
			a[0][2]='\0';
			x=0;
			b=0;
		}
		z=0;
		for(j=0;a[j][z]!='\0';j++)
		{
			for(y=0;a[j][z]!='\0';y++,z++){}
			for(z=0;a[j][z]!='\0';z++)
			{
				if(a[j][z]==x&&a[j][z]!=b)
				{
					a[j][y]=b;
					a[j][y+1]='\0';
					break;
				}
				else if(a[j][z]==b&&a[j][z]!=x)
				{
					a[j][y]=x;
					a[j][y+1]='\0';
					break;
				}
				else
				{
					a[j+1][0]=x;
					a[j+1][1]=b;
				}
			}
		}
	}
}
void found(int a[100][100],int n)
{
	int b=0,x=0,y=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		for(int j=0;j<2;j++)
		{
			b=0;
			for(int z=0;z<4;z++)
			{
				if(a[j][z]==x||a[j][z]==y)
				{
					b++;
						
				}
			}
			if(b>=2)
			{
				printf("Yes!\n");
				break;			
			}
			if(b==1)
			{
				printf("No!\n");
				break;			
			}
			if(b==0)
			{
				printf("Unknown!\n");
				break;			
			}
		}
	}
}