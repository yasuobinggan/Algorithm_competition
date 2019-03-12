#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
void cut(int num)
{
    while(num>0)
    {
        ans.push_back(num%10);
        num/=10;
    }
}
int main()
{
    cin>>n;
    cut(n);
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(i==2)
        {
            for(int j=0;j<ans[i];j++)
                cout<<'B';
        }
        else if(i==1)
        {
            for(int j=0;j<ans[i];j++)
                cout<<'S';
        }
        else if(i==0)
        {
            for(int j=1;j<=ans[i];j++)
                cout<<j;
        }
    }
    return 0;
}
