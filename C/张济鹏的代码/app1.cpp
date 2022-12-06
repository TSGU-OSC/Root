#include<stdio.h>
int main()
{
	char a[100] = { "Do you trust me?" };
	char b[100] = { "I do." };
	int i=0, t;
	for (t = 0; b[t]!='\0';t++)
	{
		a[i] = b[t];
		i++;
	}
	a[i] = '\0';
	puts(a);
	return 0;
}