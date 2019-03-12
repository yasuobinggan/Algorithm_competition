/*
	uva714 
	题意：按顺序给你N个数，将这N个数分成连续的M段，使得这M段每段的和中的最大值最小，
	输出最小值（1<=N<=100000,1<=M<=N,每个数在1到10000之间），如果有多种可能的话，尽量在前面进行划分。

思路：

1、由于函数具有单调性的特征，因此可以用二分枚举的办法去实现它，这与POJ3258有非常相似的地方，但这里不需要排序。

2、输出的时候需要用到贪心的思想，既尽量往前划分。

3、大概的思路就是二分枚举求得满足题意的最大值之后，然后以这个最大值通过从后往前的方式划分成段，
如果剩余可划分段与i+1的值相等（尽量靠前），则将剩余的段往前划分，具体实现可以用一个标记数组use表示是否划分。

5、注意high_bound可能超int，所以需要long long 来存。
*/ 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
const int N=500+5;

LL pos[N];
int vis[N];
LL num,m,group;//num数组长度;m:数组中的最大数,二分查找下界;group:划分的组数 

bool is(int x)
{
	int k=1;//初始一个划分 
	LL sum=0;
	for(int i=num-1;i>=0;i++)//为了然前面的划分小 
	{
		if(sum+pos[i]<=x)
			sum+=pos[i];
		else
		{
			k++;
			sum=pos[i]; 
		}
		if(k>group)
			return false;
	}
	return true;
}

void out()//输出 
{
	
}
int main()
{
	int Case;
	cin>>Case;
	while(Case--)
	{
		LL sum=0;
		m=0;
		cin>>num>>group;
		for(int i=0;i<num;i++)
		{
			cin>>pos[i];
			if(pos[i]>m)
				m=pos[i];
			sum+=pos[i];
		}
		int mid;
		while(m < sum)//二分上界，下界 
		{
			mid=(sum+m)/2;
			if(is(mid))
				sum=mid;
			else
				m=mid+1;
		}
		out();
	}
	return 0;
}
