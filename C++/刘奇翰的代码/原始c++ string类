#include<iostream>
#include<string>

class string
{
private:
    char *m_Buffer;//缓冲区存储字符串
    unsigned int m_Size;//记录字符串大小
public:
    string(const char* string)
    {
        m_Size=strlen(string);
        m_Buffer=new char[m_Size+1];//+1是为了存储结束符\0
        memcpy(m_Buffer,string,m_Size+1);
    }
    
    ~string()
    {
        delete[] m_Buffer;//有new就有delete
    }

    string(const string& other)//提供字符串复制的方法
        : m_Size(other.m_Size)
    {    
        m_Buffer=new char[m_Size+1];
        memcpy(m_Buffer,other.m_Buffer,m_Size+1);
    }

    friend std::ostream& operator <<(std::ostream& stream,const string& string);//friend声明友元函数，可以调用类的私有属性
};

std::ostream& operator<<(std::ostream& stream,const string& string)//运算符重载
{
    stream<<string.m_Buffer;
    return stream;
}

int main()
{
    string string0="Jack";
    string second=string0;
    std::cout<<string0<<std::endl;
    std::cout<<second<<std::endl;
    return 0;
}