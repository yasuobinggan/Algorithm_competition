#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int cnt[105];
int tar[105];
int out[105];
int find(int num,int n)
{
	for(int i=0;i<n;i++)
	{
		if(cnt[i]==num)
			return i;
	}
	return -1;
}
void Callatz(int num,int n)
{
	for(int i=1;i<n;i++)
	{
		if(num%2==0)
		{
			num/=2;
			tar[find(num,n)]=1;
		}
		else
		{
			num=(num*3+1)/2;
			tar[find(num,n)]=1;
		}	
	}
}
int main()
{
	while(cin>>n)
	{
		//memset(cnt,0,sizeof(cnt));
		memset(tar,0,sizeof(tar));
		//memset(out,0,sizeof(out));
		for(int i=0;i<n;i++)
		{
			cin>>cnt[i];
		}
		for(int i=0;i<n;i++)
		{
			if(tar[i]==0)
				Callatz(cnt[i],n);
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(!tar[i])
			{
				out[count++]=cnt[i];
			}	
		}
		sort(out,out+count);	
		for(int i=count-1;i>=0;i--)
		{
			cout<<out[i]; 
			if(i!=0)
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
 } 
