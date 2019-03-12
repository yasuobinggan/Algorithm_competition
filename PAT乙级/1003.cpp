#include<iostream>
#include<algorithm>
#include<cstring>
#include<string> 
using namespace std;
int n;
char cnt[105];
int judge[3];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin.getline(cnt,105);
		
		int j;
		for(j=0;j<strlen(cnt);i++)
		{
			if(cnt[j]=='p')
			{
				judge[0]=1;
				break;
			}
			}
			for(j=0;j<strlen(cnt);i++)
			{
				if(cnt[j]=='A')
				{
					judge[1]=1;
					break;
				}
			}
			for(j=0;j<strlen(cnt);i++)
			{
				if(cnt[j]=='T')
				{
					judge[2]=1;
					break;
				}
			}
			for(j=0;j<3;j++)
			{
				if(judge[j]!=1)
					break;
			}
			if(j==3)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			memset(judge,0,sizeof(judge));
	}
	return 0;
 } 
