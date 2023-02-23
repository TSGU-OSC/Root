#include <iostream>
using std::cout;//和使用命名空间同理
using std::endl;
#define Pi 3.14159//定义圆周率

class Circle//定义一个圆类
{
private:
    double r;
public:
    Circle(double r)//构造函数
        :r(r)
    {}
    double GetArea() { return Pi*r*r; }
    double GetLength() { return Pi*2*r; }
    ~Circle()//析构函数
    {}
};

class Rectangle//定义一个长方形类
{
private:
    double lenth,width;
public:
    Rectangle(double lenth,double width)
        :lenth(lenth),width(width)
    {}
    double getS() { return lenth*width; }
    double getC() { return (lenth+width)*2; }
    ~Rectangle()
    {}
};

int main()
{
    Rectangle test(3,4);
    
    cout<<"长方形面积:"<<test.getS()<<endl;
    cout<<"长方形周长:"<<test.getC()<<endl;

    Circle circle(2);
    cout<<"圆面积:"<<circle.GetArea()<<endl;
    cout<<"圆周长:"<<circle.GetLength()<<endl;

    return 0;
}