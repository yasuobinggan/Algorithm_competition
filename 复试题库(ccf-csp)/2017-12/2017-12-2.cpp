//Ô¼Éª·ò»·
//Ä£Äâ
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int val[maxn];
bool outed[maxn];//trueÌÔÌ­
int n,k;
bool judge(int num)//ÅĞ¶ÏÊÇ·ñÌÔÌ­:trueÌÔÌ­
{
    if(num%k==0)
        return true;
    if(num%10==k)
        return true;
    return false;
}
/*
bool getwin(int &ans)//trueÓÎÏ·Ê¤Àû
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(outed[i]==false)
        {
            ans=i;
            cnt++;
        }
    }
    if(cnt==1)
        return true;
    else
        return false;
}
*/
int main()
{
    cin>>n>>k;
    memset(outed,false,sizeof(outed));
    int cnt=0;
    int len=0;
    int ans=0;
    while(true)
    {
        for(int i=1;i<=n;i++)
        {
            if(outed[i]==false)
            {
                if(len==n-1)
                {
                    ans=i;
                    //break;
                }
                cnt++;
                if(judge(cnt))
                {
                    len++;
                    outed[i]=true;
                }

            }
        }

        if(len==n)
            break;
    }
    cout<<ans;
    return 0;
}
