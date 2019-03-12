#include<bits/stdc++.h>
using namespace std;
string DAY[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
map<char,int> m1;
map<char,int> m2;
void testout()
{
    cout<<"输出"<<endl;
    for(map<char,int>::iterator it=m1.begin();it!=m1.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
}
void process1(string P1,string P2)
{
    //string PP1;
    for(int i=0;i<P1.size();i++)
    {
        if(0<=P1[i]-'A'&&P1[i]-'A'<=26)
        {
            m1[P1[i]]=1;
        }
    }
    //testout();
    //string PP2;
    int cnt=0;
    for(int i=0;i<P2.size();i++)
    {
        if(0<=P2[i]-'A'&&P2[i]-'A'<=26)
        {
            if(m1[P2[i]]==1)
            {
                //第二个匹配
                if(cnt==1)
                {
                    cout<<9+P2[i]-'A'+1<<':';
                    break;
                }
                else
                {
                    //cout<<P2[i]<<endl;
                    //第一个匹配
                    cout<<DAY[P2[i]-'A']<<" ";
                    cnt++;
                }
            }
        }
    }

}
void process2(string U1,string U2)
{
    for(int i=0;i<U1.size();i++)
    {
        if(0<=U1[i]-'a'&&U1[i]-'a'<=26 || 0<=U1[i]-'A'&&U1[i]-'A'<=26)
        {
            m2[U1[i]]=i;
        }
    }
    for(int i=0;i<U2.size();i++)
    {
        if(0<=U2[i]-'a'&&U2[i]-'a'<=26 || 0<=U2[i]-'A'&&U2[i]-'A'<=26)
        {
            if(m2[U2[i]]==i)
            {
                printf("%02d",i);
            }
        }
    }
}
int main()
{
    string P1,P2;
    string U1,U2;
    //cout<<'N'-'A'<<endl;
    cin>>P1>>P2;
    cin>>U1>>U2;
    process1(P1,P2);
    process2(U1,U2);
    return 0;
}
