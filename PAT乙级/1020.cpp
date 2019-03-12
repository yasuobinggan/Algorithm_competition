//Ì°ÐÄ 
//#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int num;
int big;
typedef struct node
{
	double bi;
	double wei;
	double val; 
}stan;
stan s[1005];
double sum=0;
bool cmp(stan a,stan b)
{
	if(a.bi>b.bi)
		return true;
}
void msort()
{
	int i,j;
	stan temp;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1-i;j++)
		{
			if(s[j].bi<s[j+1].bi)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
}
int main()
{
	while(scanf("%d%d",&num,&big)!=EOF)
	{
		for(int i=0;i<num;i++)
			scanf("%lf",&s[i].wei);
		for(int i=0;i<num;i++)
			scanf("%lf",&s[i].val);
		for(int i=0;i<num;i++)
		{
			s[i].bi=s[i].val/s[i].wei;
		}
		msort();
		//sort(s,s+num,cmp);
		int i=0;	
		while(big>0)
		{
			if(big>=s[i].wei)
			{
				big-=s[i].wei;
				sum+=s[i].val;
				i++;
			}
			else
			{
				sum+=big*s[i].bi;
				big=0;
			}
		}
		printf("%.2f\n",sum);	
	}
	return 0;
}
