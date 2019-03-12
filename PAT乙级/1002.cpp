#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
string hanzi[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char num[105];
stack<int> q;
int main()
{
	while(cin.getline(num,105))
	{
		int length=cin.gcount()-1;
		//cout<<"length:"<<length;
		int sum=0;
		int i;
		for(i=0;i<length;i++)
		{
			sum+=(num[i]-'0');
		}
		while(sum>0)
		{
			q.push(sum%10);
			sum/=10;
		}
		while(!q.empty())
		{
			if(q.size()==1)
				cout<<hanzi[q.top()];
			else
				cout<<hanzi[q.top()]<<" ";
			q.pop();
		}
		cout<<endl;
		
	}
	return 0;
}
