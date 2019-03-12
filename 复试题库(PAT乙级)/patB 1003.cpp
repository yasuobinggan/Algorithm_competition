#include<bits/stdc++.h>
using namespace std;
int n;
bool judge1(string input)
{
    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='P'||input[i]=='A'||input[i]=='T')
        {
            continue;
        }
        else
            return false;
    }
    return true;
}
bool judge2(string &input)
{
    string output;
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    int i=0;
    while(input[i]=='A'&&i<input.size())
    {
        cnt1++;
        i++;
    }
    ++i;
    while(input[i]=='A'&&i<input.size())
    {
        cnt2++;
        i++;
    }
    ++i;
    while(input[i]=='A'&&i<input.size())
    {
        cnt3++;
        i++;
    }
    //cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
    if(cnt2==0)
        return false;
    if(cnt1*cnt2==cnt3)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    cin>>n;
    getchar();
    string input;
    //string output;
    for(int i=0;i<n;i++)
    {
        getline(cin,input);
        if(judge1(input)&&judge2(input))
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
