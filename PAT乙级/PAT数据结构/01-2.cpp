//continuous连续的 
//element元素
//in case that 为了，如果 
//index 复数 indecs 
#include<cstdio>
using namespace std;

//const int maxn=100000+5;
//一.复制数组 二.记录下标 
#define maxn 100000 
int cnt[maxn];
int maxsub[maxn];
int start,end;
int cur,max;
int main()
{
	cur=max=0;
	start=end=0;
	
	int L;
	scanf("%d",&L);
	for(int i=0;i<L;i++)
	{
		scanf("%d",&cnt[i]);
		cur+=cnt[i];
		 
		if(cur<0)
		{
			
			cur=0;
		}
			
		if(cur>max)
		{
			end=i;
			max=cur;
		}
		
	}
	//找初始下标
	int ans=max;
	int end1=end;
	while((ans>0||cnt[end1]==0)&&end1>0)
	{
		ans-=cnt[end1--];
	 } 
	start=end1+1;
	if(max==0)
	{
		printf("%d %d %d",max,cnt[0],cnt[L-1]);	
	 } 
	else
	{
		printf("%d %d %d",max,cnt[start],cnt[end]);
	}
	return 0;
} 
 
