//±©Á¦+Ä£Äâ
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int r[maxn];
int main()
{
    int n;
    cin>>n;
    int minlen=10005;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }

    int MAX=-1;
    for(int i=1;i<=n;i++)
    {
        int len=0;
        minlen=10005;
        for(int j=i;j<=n;j++)
        {
            if(r[j]<minlen)
            {
                minlen=r[j];
            }
            len++;
            if(minlen*len>MAX)
            {
                MAX=minlen*len;
                //cout<<"×ø±ê"<<i<<" "<<j;
                //cout<<"!"<<MAX<<endl;
            }
        }
    }
    cout<<MAX;
    return 0;
}
