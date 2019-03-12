#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
char line[85][85];
int main()
{
	int i=0;
	while(cin>>line[i])
	{
		/*
		char temp;
		for(int i=0;i<=strlen(line)/2;i++)
		{
			temp=line[i];
			line[i]=line[strlen(line)-i];
			line[strlen(line)-i]=temp;
		}
		cout<<line<<endl;
		*/
		i++;
	}
	for(i=i-1;i>=0;i--)
	{
		cout<<line[i]<<" ";
	}
	cout<<endl;
	return 0;
}
