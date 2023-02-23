//用枪射击怪兽，枪可装弹6发，每发弹杀伤力20，怪有血量110，盾牌可格挡10伤害
#include<iostream>
#include<unistd.h>
using std::cout;
using std::endl;

#ifdef _WIN32
#incldue<windows.h>
#endif

void sleep_cp(unsigned int seconds){
    #ifdef _WIN32
        Sleep(seconds * 1000);  // windows下的Sleep函数是以毫秒为单位的
    #else
        usleep(seconds * 1000000); // unix/linux下的usleep函数是以微秒为单位的
    #endif
}

class Beast
{
public:
    int bloodvalue;
    Beast() 
    {}
    void SetBeastBlood(int b)
    {
        bloodvalue=b;
    }

};

class Shield
{
public:
    int shieldvalue;
    Shield()
    {}
    void SetShield(int s)
    {
        shieldvalue=s;
    }
};

class Gun:public Beast,public Shield
{
public:
    int bullets,hurtvalue;
    Gun()
    {}
    void SetGun(int b,int h)
    {
        bullets=b;
        hurtvalue=h;
    }
    bool Hurt()
    {
        if(bloodvalue>0&&bullets>0) 
        {
            bullets--;
            if(shieldvalue>=hurtvalue) return true;
            else
            {
                bloodvalue-=hurtvalue;
                bloodvalue+=shieldvalue;
                return true;
            }   
        }
        else 
        {
            if(bloodvalue) cout<<"No Bullets!"<<endl;
            else cout<<"The beast is dead!"<<endl;
            return false;
        }
    }
    void InformationPrint()
    {
        cout<<"The Beast Health Rest:"<<bloodvalue<<endl;
        cout<<"The Bullets Rest:"<<bullets<<endl;
    }
};

int main()
{
    Gun gun1;
    gun1.SetGun(6,20);
    gun1.SetBeastBlood(110);
    gun1.SetShield(10);
    bool returnvalue;
    do
    {
        sleep_cp(1);
        gun1.InformationPrint();
        returnvalue=gun1.Hurt();   
    } while (returnvalue);
    
    return 0;
}