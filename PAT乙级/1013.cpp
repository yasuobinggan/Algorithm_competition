#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
int Pm,Pn;
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
	while(cin>>Pm>>Pn)
	{
		int count=0,count1=0;
		for(int i=2;i<=INT_MAX;i++)
		{
			if(judge(i))
			{
				count++;
				if(count==Pn)
				{
					cout<<i<<endl;
					break;
				}	
				if(count>=Pm&&count<Pn)
				{
					count1++;
					if(count1%10==0)
						cout<<i<<endl;
					else
						cout<<i<<" ";
				}	
			}
		}
	}
	return 0;
}
