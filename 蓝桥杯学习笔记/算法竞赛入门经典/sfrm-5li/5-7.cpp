/*
丑数 
	一.^以当前丑数为主
	二.已生成的三个丑数为主，进行队列操作 
*/
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
int ugly[10000];
int getUglyNumber(int n)
{
	int id2,id3,id5,i;
	int u2,u3,u5;
	int min_n;
	id2=id3=id5=0;
	min_n=ugly[0]=1;
	i=1;
	while(i<n)
	{
		u2=ugly[id2]*2;
		u3=ugly[id3]*3;
		u5=ugly[id5]*5;
		min_n=min(u2,min(u3,u5));
		//不用else if，因为数据重叠时下标也增加 
		if(min_n==u2)
			id2++;
		if(min_n==u3)
			id3++;
		if(min_n==u5)
			id5++;
		ugly[i]=min_n;
		i++;
	}
	return ugly[i-1];
}
int main()
{
	int n;
	cin>>n;//获得第几个丑数 
	cout<<getUglyNumber(n)<<endl; 
	return 0;
}
