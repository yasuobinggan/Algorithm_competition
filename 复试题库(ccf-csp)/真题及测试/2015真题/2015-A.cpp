#include<bits/stdc++.h>
using namespace std;
bool judge(int num)
{
    if(i==2)
        return true;
    for(int i=2;i<num/2;i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}

int main()
{
    return 0;
}
