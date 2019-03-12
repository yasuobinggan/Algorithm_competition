//错误 
//判断图是否连通 
//无根树转有根树 
//acylic hence adjacent components
#include<bits/stdc++.h>
using namespace std;
const int maxl=1e4+5;
int N;
vector<int> G[maxl];
int deep[maxl];
bool vis[maxl];
bool treejudge(int node)
{
	for(int i=0;i<G[node].size();i++)
	{
		if(vis[G[node][i]]==false)
			return false;
	}
	return true;
}
void dfs(int root,int node,int length)
{
	if(length>deep[root])
	{
		deep[root]=length;
	}
	//递归边界
	if(treejudge(node))
	{
		return;
	 }  
	for(int i=0;i<G[node].size();i++)
	{
		int curnode=G[node][i]; 	
		if(vis[curnode]==false)
		{
			vis[curnode]=true;
			dfs(root,curnode,length+1);
		}
	} 
}
void dfs_f(int node)
{
	if(treejudge(node))
	{
		return;
	 }  
	for(int i=0;i<G[node].size();i++)
	{
		int curnode=G[node][i]; 	
		if(vis[curnode]==false)
		{
			vis[curnode]=true;
			dfs_f(curnode);
		}
	}
}
int find_c_n()//找连通分量的数量 
{
	fill(vis,vis+maxl,0);
	int ans=0;
	for(int i=1;i<N;i++)
	{
		if(vis[i]==false)
		{
			vis[i]=true;
			dfs_f(i);
			ans++;
		}
	}
	return ans;
}
int main()
{
	cin>>N;
	for(int i=1;i<=N-1;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int result=find_c_n();
	if(result>1)
	{
		cout<<"Error: "<<result<<" components";
		exit(0);	
	}
	fill(deep,deep+maxl,0);
	int deepest=0;
	for(int i=1;i<=N;i++)
	{
		fill(vis,vis+maxl,0);
		vis[i]=true;
		dfs(i,i,1);
		if(deep[i]>deepest)
		{
			deepest=deep[i];
		}
	}
	for(int i=1;i<=N;i++)
	{
		if(deep[i]==deepest)
			cout<<i<<endl;
	}
	return 0;
 } 
/*
5
1 2
1 3
1 4
2 5

5
1 3
1 4
2 5
3 4
*/
