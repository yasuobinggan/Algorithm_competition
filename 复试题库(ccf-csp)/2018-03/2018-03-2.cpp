//ÂìÒÏ¸ĞÃ°
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,L,t;
struct ball{
    int pos;
    int dir;//·½Ïò
};
ball b[maxn];
void testout()
{
    for(int i=1;i<=n;i++)
    {
        cout<<b[i].pos<<" ";
    }
    cout<<endl;
}
int main()
{
    cin>>n>>L>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i].pos;
        b[i].dir=1;
    }
    int cnt=0;
    while(cnt<t)
    {
        cnt++;
        for(int i=1;i<=n;i++)
        {
            b[i].pos+=b[i].dir;
            //Åö×²µ½±ß½çÅĞ¶Ï
            if(b[i].pos==L||b[i].pos==0)
            {
                b[i].dir=0-b[i].dir;
            }
        }
        //Ğ¡ÇòÅö×²ÅĞ¶Ï
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(b[i].pos==b[j].pos)
                {
                    /*
                    ball temp;
                    temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;
                    */
                    b[i].dir=0-b[i].dir;
                    b[j].dir=0-b[j].dir;
                }

            }
        }
    }
    //Êä³ö
    testout();
    return 0;
}
