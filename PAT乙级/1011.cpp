#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int n;
//输出bool变量输出的是1或0 
int main()
{
	cin>>n;
	int i=1;
	while(i<=n)
	{
		ll a,b,c;
		//bool flag;
		cin>>a>>b>>c;
		if(a+b>c)
			cout<<"Case #"<<i<<": "<<"true"<<endl;	
		else
			cout<<"Case #"<<i<<": "<<"false"<<endl;
		i++;
	}
	return 0;
}
