/*
	树，uva442
		这个题很经典 
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
//用权值做各点编号 
#define maxn 10000+5
int in_order[maxn],post_order[maxn];
int lch[maxn],rch[maxn];//左子树编号，右子树编号  
int n;
bool read_list(int *a)
{
	/*
	char buf[maxn];
	if(!cin.getline(buf,maxn))
		return false;
	int i;
	for(i=0;buf[i]!=EOF;i++)
	{
		a[i]=buf[i];
		cout<<a[i]<<endl;
	}
	*/	
	string line;
	if(!getline(cin,line))
		return false;
	stringstream ss(line);
	n=0;int x;
	while(ss>>x)
		a[n++]=x;
	return n>0;
}
int build(int L1,int R1,int L2,int R2)
{
	//返回条件 
	if(L1>R1)
		return 0;//空树
	//构建节点 
	int root=post_order[R2];
	int p=L1;
	//获得当前节点左子树的数目
	while(in_order[p]!=root)
		p++;
	int cnt=p-L1;
	//建立左子树，右子树 
	lch[root]=build(L1,p-1,L2,L2+cnt-1);
	rch[root]=build(p+1,R1,L2+cnt,R2-1);
	return root; 
}
int best,best_sum;//best最小点，best_sum最小线 
//这个函数以前可能写错了，值得反思 
void dfs(int root,int sum)//先序遍历构造树 
{
	sum+=root;
	if(!lch[root]&&!rch[root])//叶子节点
	{
		if(sum<best_sum||(sum==best_sum&&root<best))
		{
			best=root;
			best_sum=sum;
		}
	} 
	if(lch[root])dfs(lch[root],sum);
	if(rch[root])dfs(rch[root],sum);
}
int main()
{
	
	while(read_list(in_order))
	{
		read_list(post_order);
		build(0,n-1,0,n-1);
		best_sum=100000000;
		dfs(post_order[n-1],0);
		cout<<"最小边最小点权值:"<<best<<"\t最小边权值:"<<best_sum<<endl;
	}
	return 0;
}
