#include<stdio.h>
#include<math.h>
void Base_change(int sum);
int Base_16_10_change(int a,char n[10]);
int main()
{
	char n[10];
	int a=0,sum=0;
	scanf("%s",n);
	for(;n[a]!='\0';a++){}
	sum=Base_16_10_change(a,n);
	Base_change(sum);
	printf("\n");
}
int Base_16_10_change(int a,char n[10])
{
	int sum=0,b=0;
	b=a;
	for(int i=0;i<a;i++)
	{
		if(b>1)
		{
			sum=sum+((int)n[i]-48)*pow(16,--b);
		}
		if(i==a-1)
		{
			switch(n[i])
			{
				case 'A':sum+=10;break;
				case 'B':sum+=11;break;
				case 'C':sum+=12;break;
				case 'D':sum+=13;break;
				case 'E':sum+=14;break;
				case 'F':sum+=15;break;
			}
		}
	}
	return sum;
}
void Base_change(int sum)
{
	if(sum!=0)
	{
		Base_change(sum/8);
		printf("%d",sum%8);
	}
}