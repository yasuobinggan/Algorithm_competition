/*
	倒水问题 uva10603 
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node{
	int v[3];
	int dist;//？最小到水量 
	bool operator<(const Node& rhs) const{
		return dist>rhs.dist;
	}
};

const int maxn=200+5;
int vis[maxn][maxn],cap[3],ans[maxn];//vis a,b水量,cap容积数组,ans到水量 

void update_ans(const Node& u)
{
	for(int i=0;i<3;i++)
	{
		int d=u.v[i];
		if(ans[d]<0||u.dist<ans[d])
			ans[d]=u.dist;
	}
}
void solve(int a,int b,int c,int d)
{
	cap[0]=a;cap[1]=b;cap[2]=c;
	memset(vis,0,sizeof(vis));
	memset(ans,-1,sizeof(ans));
	priority_queue<Node> q;//优先队列
	
	Node start;
	start.v[0]=0;start.v[1]=0;start.v[2]=c;
	start.dist=0;
	q.push(start);
	vis[0][0]=1;
	
	while(!q.empty())
	{
		Node u=q.top();
		q.pop();
		update_ans(u);
		
		if(ans[d]>=0)//到达结果 
			break;
		
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(i!=j)
				{
					if(u.v[i]==0||u.v[j]==cap[j])//无需操作 
						continue;
					int amount=min(cap[j],u.v[i]+u.v[j])-u.v[j];//是填满j容器，还是倒空i的水 
					Node u2;
					memcpy(&u2,&u,sizeof(u));//这个操作很神奇 
					u2.dist=u.dist+amount;
					u2.v[i]-=amount;
					u2.v[j]+=amount;
					if(!vis[u2.v[0]][u2.v[1]])//未访问标记访问入队列 
					{
						vis[u2.v[0]][u2.v[1]]=1;
						q.push(u2);
					}
				}
			}
		}
	} 
	
	while(d>=0)//在ans表里递减查找，查找最接近的水量 
	{
		if(ans[d]>=0)
		{
			cout<<ans[d]<<" "<<d;
			return; 
		}
		d--;
	}
} 
int main()
{
	int T,a,b,c,d;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		solve(a,b,c,d);
	}
	return 0;
} 
