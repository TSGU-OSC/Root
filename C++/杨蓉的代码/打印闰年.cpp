#include<iostream>
int main()
#define year
{
	int leap_year;
	int common_year;
	for (int i = 2000; i < 3000; i++)
	{
		if (i % 400==0 || (i%4==0 && i%100!=0)) 
			std::cout << "i=" << i << std::endl;
	}
	return 0;
}