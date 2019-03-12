#include<iostream>
#include<string>
#include<set>
#include<sstream> 
using namespace std;
set<string> dict;//string集合 
int main()
{
	string s,buf;
	int i;
	while(cin>>s)
	{
		for(i=0;i<s.length();i++)
		{
			if(isalpha(s[i]))
				s[i]=tolower(s[i]);
			else
				s[i]=' '; 
		}
		stringstream ss(s);//封装成流
		while(ss>>buf)
			dict.insert(buf);//插入一个流 
	}
	
	for(set<string>::iterator it=dict.begin(); it!=dict.end(); ++it)
		cout<<*it<<"\n"; 
	return 0;
}
