#include<bits/stdc++.h>
using namespace std;
int y,d;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

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
    cin>>y>>d;
    int curyue=1,curday=0;
    //∂‘»ÚƒÍ≈–∂œ
    if(leapyear(y))
        month[2]++;

    for(int i=1;i<=12;i++)
    {
        if(d-month[i]>0)
        {
            d-=month[i];
            curyue++;
        }
        else
        {
            cout<<curyue<<endl;
            cout<<d;
            break;
        }
    }
    return 0;
}
//2015
//80

//2000
//40
