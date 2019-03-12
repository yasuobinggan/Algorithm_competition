#include<iostream>
using namespace std;
#define maxn 1000
struct D{
	int x;//系数 
	int y;//指数 
};
D a[maxn],b[maxn];
D s[maxn],mul[maxn];
int la,lb;
int op_sum()
{
	int ai=0,bi=0;
	int si=0;
	while(ai<la&&bi<lb)
	{
		if(a[ai].y>b[bi].y)
		{
			s[si].x=a[ai].x;
			s[si].y=a[ai].y;
			ai++;
		}
		if(a[ai].y==b[bi].y)
		{
			s[si].x=a[ai].x+b[bi].x;
			s[si].y=a[ai].y;
			ai++;bi++;
		}
		if(a[ai].y<b[bi].y)
		{
			s[si].x=b[ai].x;
			s[si].y=b[ai].y;
			bi++;
		}
		si++;
	}
	while(ai<la)
	{
		s[si].x=a[ai].x;
		s[si].y=a[ai].y;
		ai++;
		si++;
	}
	while(bi<lb)
	{
		s[si].x=b[ai].x;
		s[si].y=b[ai].y;
		bi++;
		si++;
	}
	return si;
}
int multiply()
{
	return 0;	
}
int main()
{
	cin>>la;
	for(int i=0;i<la;i++)
	{
		cin>>a[i].x;
		cin>>a[i].y;
	}
	cin>>lb;
	for(int i=0;i<lb;i++)
	{
		cin>>b[i].x;
		cin>>b[i].y;
	}
	int lens=op_sum();
	for(int i=0;i<lens;i++)
	{
		cout<<s[i].x<<" "<<s[i].y;
		if(i!=lens-1)
			cout<<" ";
		
	 } 
	return 0;
}
