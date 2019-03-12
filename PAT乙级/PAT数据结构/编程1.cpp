#include<cstdio>

const int maxn=100000+5;
int cnt[maxn];
int main()
{
	int cur=0,max=0;
	int L;
	scanf("%d",&L);
	for(int i=0;i<L;i++)
	{
		scanf("%d",&cnt[i]);
		cur+=cnt[i];
		if(cur<0)
			cur=0;
		if(cur>max)
		{
			max=cur;
		}
	}
	printf("%d",max);
	return 0;
} 
