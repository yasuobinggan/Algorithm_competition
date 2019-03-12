#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXD 20
int a[1<<20];
int main()
{
	int D,I;
	while(cin>>D>>I)
	{
		memset(a,0,sizeof(a));
		int k,n,i;
		n=(1<<D)-1;
		for(i=1;i<=I;i++)
		{
			k=1;
			while(1)
			{
				a[k]=!a[k];
				k=a[k]?2*k:2*k+1;
				//k=a[k]==0?k+1
				if(k>n)
					break; 
			} 
			 
		}
		cout<<k/2<<endl;//出界前的//这位置相当于直接省略了判断叶节点的开闭 
	}
	return 0;
} 
