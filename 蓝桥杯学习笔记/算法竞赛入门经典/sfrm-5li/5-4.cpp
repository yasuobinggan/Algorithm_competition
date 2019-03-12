#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<string> words;
map<string,int> cnt;
//为什么这个位置用const和引用形参
//规范化字符串 
string repr(const string &s) 
{
	string ans=s;
	int i;
	for(i=0;i <s.length();i++)
	{
		ans[i]=tolower(ans[i]);
	}
	sort(ans.begin(),ans.end());// 
	return ans; 
} 
int main()
{
	int n=0;
	string s;
	while(cin>>s)
	{
		if(s=="#")
			break;
		words.push_back(s);
		
		string r=repr(s);
		if(!cnt.count(r))//如果r没出现过,键r的值为0 
			cnt[r]=0;
		cnt[r]++;
	}
	
	vector<string> ans;//存储结果的数组 
	for(int i=0;i<words.size();i++)//从words中筛选string加入ans 
	{
		if(cnt[repr(words[i])]==1)//repr(words[i])等价于上文中的r 
			ans.push_back(words[i]);
	} 
	//排序后输出 
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";
		
	return 0;
}
