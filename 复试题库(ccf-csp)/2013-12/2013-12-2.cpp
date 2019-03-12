#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin>>input;
    int cnt=1;
    int res=0;
    for(int i=0;i<input.size()-1;i++)
    {
        if(0<=input[i]-'0'&&input[i]-'0'<=9)
        {
            res+=(input[i]-'0')*cnt;
            cnt++;
        }
    }
    char ans;
    if(res%11==10)
    {
        ans='X';
    }
    else
        ans=res%11+'0';
    if(ans==input[12])
        cout<<"Right";
    else
    {
        input[12]=ans;
        cout<<input<<endl;
    }
    return 0;
}
