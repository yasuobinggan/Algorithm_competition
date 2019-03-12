#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
char A[15],da,B[15],db;
int main()
{
	while(cin>>A>>da>>B>>db)
	{
		int pa=0,pb=0;
		int ca=0,cb=0;
		for(int i=0;i<strlen(A);i++)
		{
			if(A[i]==da)
			{
				pa*=10;
				pa+=da-'0';
			}
		}
		for(int i=0;i<strlen(B);i++)
		{
			if(B[i]==db)
			{
				pb*=10;
				pb+=db-'0';
			}
		}
		cout<<pa+pb<<endl;
	}
	return 0;
}
