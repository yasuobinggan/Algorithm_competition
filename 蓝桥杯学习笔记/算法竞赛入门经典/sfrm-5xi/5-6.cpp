/*
	对称轴uva1595
	一.使用map，但是感觉map不够灵活 
*/
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map<int,int> cnt;//纵轴值，横轴值 
bool judge()
{
	double aw1,aw2;
	//迭代器走起,it,j实际上是指针 
	map<int,int>::iterator it,j;//j为里层判断迭代器 
	double sum;
	for(it=cnt.begin();it!=cnt.end();it=it+cnt.count(it->first))
	{
		if(it==cnt.begin())
		{
			if(cnt.count(it->first)%2==0)
			{	
				sum=0;
				for(j=it;j<(it+cnt.count(it->first));j++)
					sum+=j->second;
				sum/=cnt.count(it->first);
				aw1=sum;	
			}
			else
			{
				aw1=it.
			}	
		}
		else
		{
			if(cnt.count(it->first)%2==0)
			{	
				sum=0;
				for(j=it;j<it+cnt.count(it->first);j++)
					sum+=j->second;
				sum/=cnt.count(it->first);
				aw2=sum;
				if(aw2!=aw1)
					return 0;	
			}
			else
			{
				aw2=cnt[(it+it+cnt.count(it->first)-1)/2];
				if(aw2!=aw1)
				return 0;
			}
		}
		//
	}
	
	return 1;
}
int main()
{
 	int n,a,b;
 	cin>>n;
 	while(n-->0)
 	{
 		cin>>a>>b;
 		map[b]=a;
 	}
 	if(judge())
 		cout<<"YES\n";
 	else
 		cout<<"NO\n";
	return 0;
}
