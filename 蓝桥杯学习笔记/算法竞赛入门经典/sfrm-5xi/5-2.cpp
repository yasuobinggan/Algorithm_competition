/*
Ducci序列，uva1594
水  
*/
#include<iostream>
#include<cstdlib>
#include<cmath> 
#include<algorithm>
using namespace std; 

#define m_l 20

int main()
{
	int a[m_l],n,i;
	int ans=0;
	int flag;
	int sum; 
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	while(ans<1000)
	{
		sum=0;
		flag=a[0];
		for(i=0;i<n-1;i++)
			a[i]=abs(a[i]-a[i+1]);
		a[n-1]=abs(a[n-1]-flag);
		for(i=0;i<n;i++)
		{
			//cout<<a[i]<<"\t";
			sum+=a[i];
		}
		//cout<<endl;	
		if(sum==0)
			break;
		ans++;
	}
	if(ans==1000)
		cout<<"循环"<<endl;
	else
		cout<<"为零"<<endl;	
	return 0;
}
