#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
#define ml 10005
int n,cnt[ml];
double tar;
double div2(double num)
{
	return num/2;
}
int main()
{
	while(cin>>n)
	{
		tar=0;
		int i;
		for(i=0;i<n;i++)
		{
			cin>>cnt[i];
		}
		sort(cnt,cnt+n);
		tar=div2(cnt[0])+div2(cnt[1]);
		for(i=2;i<n;i++)
		{
			tar=div2(tar)+div2(cnt[i]);
		}
		cout<<floor(tar)<<endl;
	}
	return 0;
}
