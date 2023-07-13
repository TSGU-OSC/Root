#include<iostream>
#define total 100
int main()
{
	int hen, chick;
	for (int i = 0; i < 100; i++)
	{
		for (int j= 0; j < 100; j++)
		{
			if ((100 - i - j) * 5 + i * 3 + j / 3 == 100 && 100-i-j>=0 &&100-i-j<=100 && j%3==0)
			{
				std::cout << "100-i-j=" << 100 - i - j <<"   " << "i=" << i <<"   " << "j=" << j << std::endl;
			}
		}
	}
	return 0;
}