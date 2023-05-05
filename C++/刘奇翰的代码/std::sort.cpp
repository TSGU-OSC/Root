#include <iostream>
#include <vector> //动态数组
#include <algorithm> //包含std::sort
//#include <functional> 

int main()
{
    std::vector<int> values = {4,2,5,1,3};//先创建一个数组

    //用functional库里面的std::greater函数来实现倒序（默认是正序）
    //std::sort(values.begin(),values.end(),std::greater<int>());
    
    std::sort(values.begin(),values.end(),[](int a,int b){
        return a > b;//这里用>就是从大到大排序,<就是从小到大排序
    });
    for(int value:values)
        std::cout<<value<<std::endl;
    return 0;
}