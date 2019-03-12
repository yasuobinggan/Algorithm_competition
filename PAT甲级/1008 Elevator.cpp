//´íÎó 
//ÂÆÇåif else ½á¹¹  
#include<bits/stdc++.h>
using namespace std;
int N;
int e[105];
int sum=0;
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>e[i];
	 }
	int cure=0;
	for(int i=0;i<N;i++)
	{
		if(e[i]>cure)
		{
			sum+=6*(abs(e[i]-cure));
			sum+=5;
			cure=e[i];
			//cout<<sum<<endl;
		}
		else if(e[i]==cure)
		{
			sum+=5;
			cout<<sum<<endl;
		}
		else if(e[i]<cure)
		{
			sum+=4*(abs(e[i]-cure));
			sum+=5;
			cure=e[i];
			//cout<<sum<<endl;
		}
	 } 
	 cout<<sum;
	return 0;
 } 
 /*
 3 2 3 1
 */
