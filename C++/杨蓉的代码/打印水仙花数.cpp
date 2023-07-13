#include<iostream>
int main()
{
	for (int i = 100; i <=999; i++)
	{
		int a;
		int b;
		int c;
		a = i / 100;
		b = i / 10 % 10;
		c = i % 100 % 10;
			if (a * a * a + b * b * b + c * c * c == i)
			{
				std::cout << a << b << c << std::endl;
			}
	}
	 
	return 0;
}