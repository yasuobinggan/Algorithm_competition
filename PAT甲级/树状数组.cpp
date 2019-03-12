#include<bits/stdc++.h>
#define lowbit(i) ((i)&(-i)))
using namespace std;
const int maxn=100010;
int c[maxn];
void update(int x,int v)//vÎªÔöÁ¿
{
    for(int i=x;i<maxn;i+=lowbit(i))
    {
        c[i]+=v;
    }
}
int getsum(int x)
{
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        sum+=c[i];
    }
    return sum;
}
int main()
{
    int n,x;
    scanf("%d",&n);
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        update(x,1);
        printf("%d\n",getsum(x-1));
    }
    return 0;
}
