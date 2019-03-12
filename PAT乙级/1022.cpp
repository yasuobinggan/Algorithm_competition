#include<iostream>
#include<algorithm>
using namespace std;
int A,B,D;
int s[10],sum=0;

int main()
{
	while(cin>>A>>B>>D)
	{
		sum=A+B;
		int i=0;
		while(sum>0)
		{
			s[i++]=sum%D;
			sum/=D;
		}
		int j;
		for(j=i-1;j>=0;j--)
			cout<<s[j];
		cout<<endl;
	}
	return 0;
}
