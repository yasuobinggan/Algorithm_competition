#include<bits/stdc++.h>
using namespace std;
double T,S=10000;
bool judge()
{
    double ans=0;
    double A=S-3500;
    if(A>80000)
    {
        ans+=(A-80000)*0.45;
        A=80000;
    }
    if(A>55000)
    {
        ans+=(A-55000)*0.35;
        A=55000;
    }
    if(A>35000)
    {
        ans+=(A-35000)*0.30;
        A=35000;
    }
    if(A>9000)
    {
        ans+=(A-9000)*0.25;
        A=9000;
    }
    if(A>4500)
    {
        ans+=(A-4500)*0.20;
        A=4500;
    }
    if(A>1500)
    {
        ans+=(A-1500)*0.10;
        A=1500;
    }
    ans+=A*0.03;
    if(S-T==ans)
        return true;
    else
        return false;
}
int main()
{
    cin>>T;
    if(T<=3500)
        cout<<T;
    else
    {
        for(S=3501;S<=150000;S+=1)
        {
            if(judge()&&S!=T)
            {
                cout<<S;
            }
        }
    }

    return 0;
}
//9255
