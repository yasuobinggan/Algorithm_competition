#include<iostream>
#include<algorithm>
using namespace std;
int cnt[10],num[50];
int main()
{
	while(cin>>cnt[0])
	{
		for(int i=1;i<10;i++)
			cin>>cnt[i];
		int length=0;
		for(int i=0;i<10;i++)
		{
			while((cnt[i]--)>0)
			{
				num[length++]=i;
			}
		}
		
		sort(num,num+length);
		
		int temp;
		int i;
		for(i=0;i<length;i++)
		{
			if(num[i]!=0)
				break;
		}
		
		temp=num[i];
		num[i]=num[0];
		num[0]=temp;
		
		for(int i=0;i<length;i++)
			cout<<num[i];
		cout<<endl;
	}
	return 0;
}
/*
typedef struct node{
	int cnt;
	int inte;
}node;
node n[10];
bool cmp(node a,node b)
{
	if(a.cnt > b.cnt)
		return true;
 } 
int main()
{
	while(cin>>n[0].cnt)
	{
		n[0].inte=0;
		for(int i=1;i<10;i++)
		{
			cin>>n[i].cnt;
			n[i].inte=i;
		}
		
		sort(n,n+10,cmp);
		
		for(int i=0;i<10;i++)
		{
			while((n[i].cnt--)>0)
				cout<<n[i].inte;
		}
	}
	return 0;
}
*/

