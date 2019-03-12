#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	vector<string> in;
	string input;
	for(int i=1;i<=n;i++)
	{
		in.clear();
		for(int j=1;j<=4;j++)
		{
			cin>>input;
			in.push_back(input);
		}	
		
		for(int j=0;j<in.size();j++)
		{
			if(in[j][2]=='T')
			{
				//cout<<in[j][2];
				cout<<in[j][0]-'A'+1;
			}
				
		}
	}
	return 0;
}
