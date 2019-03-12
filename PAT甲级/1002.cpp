//occupy占领，使用
//polynomial多项式
//nonzero非零
//exponents指数 
//coefficient系数
//respectively各自地，分别的
//accurate精确 
//decimal小数

//const定义常量 
#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+5
//const int maxn=1e10000+5;
struct node{
	int x;
	double y;
};

node a[maxn],b[maxn],c[maxn];
int k1,k2; 
int main()
{
	//x是阶，y是系数 
	
	cin>>k1;
	for(int i=0;i<k1;i++)
	{
//		cin>>a[i].x>>a[i].y;
		scanf("%d%lf",&a[i].x,&a[i].y);
	}
	
	cin>>k2;
	for(int i=0;i<k2;i++)
	{
//		cin>>b[i].x>>b[i].y;
		scanf("%d%lf",&b[i].x,&b[i].y);
	}
	
	
	int ai=0,bi=0;
	int ci=0;
	while(ai<k1&&bi<k2)
	{
		if(a[ai].x>b[bi].x)
		{
			c[ci].x=a[ai].x;
			c[ci].y=a[ai].y;
			++ai;
		}
		if(a[ai].x==b[bi].x)
		{
			c[ci].x=a[ai].x;
			c[ci].y=a[ai].y+b[bi].y;
			++ai;
			++bi;
		}
		if(a[ai].x<b[bi].x)
		{
			c[ci].x=b[ai].x;
			c[ci].y=b[ai].y;
			++bi;
			
		}
		++ci;
	}
	while(ai<k1)
	{
		c[ci].x = a[ai].x;
		c[ci].y = a[ai].y;
		ci++;
		ai++;	
	}
	while(bi<k2)
	{
		c[ci].x = b[bi].x;
		c[ci].y = b[bi].y;
		ci++;
		bi++;	
	}
	printf("%d ",ci);
	//cout<<ci<<" ";
	for(int i=0;i<ci;i++)
	{
		if(i==ci-1)
		{
			//cout<<c[i].x<<" "<<c[i].y;
			printf("%d %.1f",c[i].x,c[i].y);	
		}
		else
		{
//			cout<<c[i].x<<" "<<c[i].y<<" ";
			printf("%d %.1f ",c[i].x,c[i].y);
		}
		
	}
	return 0;
 } 
