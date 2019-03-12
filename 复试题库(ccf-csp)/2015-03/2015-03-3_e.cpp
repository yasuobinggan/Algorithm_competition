///ERROR
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int monthdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int a,b,c,y1,y2;
bool leapyear(int year)
{
    if(year%400==0)
        return true;
    else if(year%4==0&&year%100!=0)
        return true;
    else
        return false;
}
int main()
{
    cin>>a>>b>>c>>y1>>y2;
    int cnt=0;
    //y1年1月1日是星期几
    for(int i=1850;i<y1;i++)
    {
        cnt+=365+leapyear(i);
    }
    ///0-6=>1-7
    for(int year=y1;year<=y2;year++)
    {
        //a月1日星期几
        int dcnt=0;
        for(int month=1;month<a;month++)
        {
            dcnt+=monthdays[month];
            if(month==2)
                dcnt+=leapyear(year);
        }
        2+=(cnt+dcnt-1)%7;

        int ddcnt=0;
        for(int week=1;week<b;week++)
        {
            ddcnt+=7;
        }
        ddcnt+=c;
        //输出
        if(a==2)
        {
            if(ddcnt>monthdays[a]+leapyear(year))
                cout<<"none"<<endl;
            else
            {
                printf("%d/%02d/%02d\n",year,a,ddcnt);
            }
        }
        else
        {
            if(ddcnt>monthdays[a])
                cout<<"none"<<endl;
            else
            {
                printf("%d/%02d/%02d\n",year,a,ddcnt);
            }
        }
        cnt+=365+leapyear(year);
    }
    return 0;
}
