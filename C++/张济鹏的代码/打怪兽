#include<iostream>
using namespace std;
class Gun
{
    public:
    int bullets;
    int shanghai;
    void SetGun(int b,int s)
    {
        bullets=b;
        shanghai=s;
    }
    void attack()
    {
        bullets--;
    }

};
class NPC
{
    public:
    int health;
    int hurt;
    int dun;
    void SetNPC(int h1,int h2,int h3)
    {
        health=h1;
        hurt=h2;
        dun=h3;
    }
    bool start()
    {
        int b=1;
        if(dun>0)
        {
            dun=dun-hurt;
            b=0;
            if(dun<=0)
            {
                cout<<"dun="<<dun<<endl;
                health=health+dun;
                dun=0;
               b=0;
            }
        }
        if(b==1)
       {
         health=health-hurt;
       }
       if(a==0)
       {
        b=1;
       }
        if(health<=0)
        {
            cout<<"人类心中还有贪婪，我就不可能被消灭。"<<endl;
            health=0;
             cout<<"怪物血量="<<health<<endl;
            return false;
        }
        else 
        {
            cout<<"血......"<<endl;
             cout<<"怪物血量="<<health<<endl;
            return true;
        }
    }
};
int main()
{
    int b,s,h1,dun;
    bool iscontinue;
    cout<<"余弹=";
    cin>>b;
    cout<<endl;
    cout<<"伤害=";
    cin>>s;
    cout<<endl;
    cout<<"怪物血量=";
    cin>>h1;
    cout<<endl;
    cout<<"怪物盾牌值=";
    cin>>dun;
    Gun g1;
    NPC n1;
    g1.SetGun(b,s);
    n1.SetNPC(h1,s,dun);
    while(true)
    {
        _sleep(1000);
         g1.attack();
         if(g1.bullets<0)
         {
            cout<<"子弹已用尽"<<endl;
            break;
         }
        iscontinue=n1.start();
         cout<<"余弹="<<g1.bullets<<endl;
        if(iscontinue==false)
        {
            cout<<"怪物死亡"<<endl;
            break;
        }
    }
    return 0;
}
