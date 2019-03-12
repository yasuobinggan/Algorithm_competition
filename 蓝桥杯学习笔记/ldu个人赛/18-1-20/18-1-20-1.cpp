#include<stdio.h>
#include<algorithm>
using namespace std;
#define m_l 4000
void init(int p[],int n)
{
	for(int i=0;i<=n;i++)
		p[i]=-99999999;
	p[0]=0;
}
int main()
{
	int n,a,b,c;
	int i,p[m_l];
	while(scanf("%d%d%d%d",&n,&a,&b,&c)==4)
	{
		init(p,n);
		for(i=1;i<=n;i++)
		{
			if(i-a>=0)
				p[i]=max(p[i],p[i-a]+1);
			if(i-b>=0)
				p[i]=max(p[i],p[i-b]+1);
			if(i-c>=0)
				p[i]=max(p[i],p[i-c]+1);
		}
		printf("%d\n",p[n]);
	}
	return 0;
}