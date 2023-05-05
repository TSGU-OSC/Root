#include <iostream>
#include <chrono> //这里要用到C++标准库chrono里面的计数器

struct Timer//封装成了一个结构体，可以在测试函数里直接创建一个对象，即可实现计时（用struct是因为默认时public）
{
    std::chrono::time_point<std::chrono::steady_clock> start,end;//定义开始，结束的时间变量
    std::chrono::duration<float> duration;//定义中间的持续时间变量
    Timer()
    {
        start=std::chrono::high_resolution_clock::now();//创建变量时，开始计时
    }
    ~Timer()//对象被删除时，自动计算持续时间以及打印出来
    {
        end=std::chrono::high_resolution_clock::now();
        duration=end-start;
        std::cout<<duration.count()*1000.0f<<"ms"<<std::endl;//以毫秒为单位
    }
};

void Function()//用于测试的函数
{
    Timer timer;
    for(int i=0;i<100;i++)
        std::cout<<"test!\n";

}


int main()
{
    
    /*using namespace std::literals::chrono_literals;
    auto start=std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration=end-start;
    std::cout<<duration.count()*1000.0f<<"ms"<<std::endl;*/
    //以上为未封装成类的写法

    Function();//函数结束时，创建的Timer对象自动删除，运行析构函数打印持续时间
    return 0;
}