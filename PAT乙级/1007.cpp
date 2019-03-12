#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
bool judge(int number)
{
	for(int i=2;i<=sqrt(number);i++)
	{
		if(number%i==0)
			return false;
	}
	return true;
}
int main()
{
	while(cin>>n)
	{
		int count=0;
		for(int i=2;i+2<=n;i++)
		{
			if(judge(i)&&judge(i+2))
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
 } 
