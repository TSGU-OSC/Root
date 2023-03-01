#include<stdio.h>
#include<math.h>
#define lamta 589.3e-6

int main()
{
    //需要自己修改一下两行代码，初始化自己的测试数据
    double dl[10]={};//在大括号里填写左边十个环的数据，如{1,2,3,4,5,6,7,8,9,10}
    double dr[10]={};//在大括号里填写右边十个环的数据，如{1,2,3,4,5,6,7,8,9,10}
    double dm[5],dn[5],dp[5],da,r,sum=0;
    double uad,ubd,ucd,ucr;
    //data test
    printf("请确认以下两行你的记录数据正确与否\n");
    for(int i=0;i<10;i++)
    {
        printf("%.3lf\t",dl[i]);
    }
    printf("\n");
    for(int i=0;i<10;i++)
    {
        printf("%.3lf\t",dr[i]);
    }
    printf("\n");
    printf("***************************************************************************\n");
    for(int i=0;i<5;i++)
    {
        dm[i]=dr[i]-dl[i];
    }
    for(int i=0;i<5;i++)
    {
        dn[i]=dr[i+5]-dl[i+5];
    }
    printf("Dm:\t");
    for(int i=0;i<5;i++)
    {
        printf("%.3lf\t",dm[i]);
    }
    printf("\n");
    printf("Dn:\t");
    for(int i=0;i<5;i++)
    {
        printf("%.3lf\t",dn[i]);
    }
    printf("\n");

    
    printf("D^2(Dm^2-Dn^2):\t");
    for(int i=0;i<5;i++)
    {
        dp[i]=dm[i]*dm[i]-dn[i]*dn[i];
        sum+=dp[i];
        printf("%lf\t",dp[i]);
    }
    da=sum/5;
    sum=0;
    printf("\n");
    for(int i=0;i<5;i++)
    {
        sum=sum+dp[i]/(20.0*lamta);
        //printf("%lf\t",dp[i]/(20.0*lamta));
    }
    //printf("\n");
    r=sum/5;
    //printf("%lf,%lf\n",sum,r);
    sum=0;
    for(int i=0;i<5;i++)
    {
        sum=sum+pow((dp[i]-da),2);
    }
    //printf("%lf\t",sum);
    uad=sqrt(sum/20);
    ubd=0.01/sqrt(3);
    ucd=sqrt(pow(uad,2)+pow(ubd,2));
    ucr=ucd/(20*lamta);
    printf("Ua(D)= %lf,Ub(D)= %lf,Uc(D)= %lf,Uc(R)= %lf",uad,ubd,ucd,ucr);
    printf("\n\n");
    printf("R= %.10f or %.10f \n",r+ucr,r-ucr);
    return 0;
}