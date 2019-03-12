#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;
#define ml 1000
int cnt[1000];
int main()
{
	int i=0;
	while(cin>>cnt[i])
	{
		i=1;
		while(cin>>cnt[i]&&cnt[i])
		{
			i++;
		}
		int j;
		for(j=0;cnt[j+1]!=0;j+=2)
		{
			cnt[j]*=cnt[j+1];
			cnt[j+1]-=1;
			cout<<cnt[j]<<" "<<cnt[j+1];
			if(cnt[j+1]!=0)
			{
				cout<<" ";
			}
		}
		cout<<endl;
		i=0;
	}
	return 0;
 } 
