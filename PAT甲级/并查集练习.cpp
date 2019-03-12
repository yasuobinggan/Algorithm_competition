#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int father[maxn];//其中可能包括多个集合，所有集合中的所有节点是不同的 
//father[2]=1：2的父亲节点是1 
void init()//初始化 
{
	for(int i=1;i<=maxn;i++)
		father[i]=i;
	father[1]=1;
	father[2]=1;
	father[3]=2;
	father[4]=2;
	father[5]=5;
	father[6]=5;
}
//循环找根节点
int findFather1(int x)
{
	while(x!=father[x])
	{
		x=father[x];
	}
	return x;
}
//递归找根节点 
int findFather2(int x)
{
	if(x==father[x])
		return x;
//	x=father[x];
//	findFather2(x);
	findFather2(father[x]); 
}
void Union()
{
	int f1=findFather2(f1);
	int f2=findFather2(f2);
	if(f1!=f2)
		father[f1]=f2; 
 } 
int main()
{
	init();
	cout<<findFather1(3)<<endl;
	cout<<findFather2(3)<<endl;
	return 0;
 } 
