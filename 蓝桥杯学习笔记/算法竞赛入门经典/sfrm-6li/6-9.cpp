/*
	天平 
		一.在输入过程中完成判断 
		二.输入后完成判断 
		递归是一个栈的特性，递归比循环更具有记忆的特性 
*/
//输入后判断 
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 10000+5 
int a[maxn][4]; 
bool solve(int a[maxn][4],int n)
{
	int j;
	for(j=0;j<n;j++)
	{
		
	}
}
int main()
{
	int i=0;
	while(cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3])
	{
		++i;
	}
	if(solve(a,i))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
//边输入边判断 
