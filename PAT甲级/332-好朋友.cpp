//并查集是一棵树
//并查集的初始化，根的数目就是集合的数目
#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int n,m;
int father[maxn];
int ans;
void Init()
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
	}
 }
/*
int f_f(int x)//路径压缩:深度遍历后回溯//递归中一层处理一层的事，不这么处理会导致回溯混乱
{
	if(x==father[x])//返回根节点
		return x;

	//会导致最初的节点无法指向根节点
	//x=father[x];
	//int Fa=f_f(x);
	//father[x]=Fa;

	int Fa=f_f(father[x]);
	father[x]=Fa;
	//返回上一层,回溯的关键
	return Fa;
}
*/
int f_f(int x)
{
    if(x==father[x])
            return x;
    return father[x]=f_f(father[x]);
}
void Union(int a,int b)
{
	int fa=f_f(a);
	int fb=f_f(b);
	if(fa!=fb)
		father[fa]=fb;
}
int main()
{
	ans=0;
	cin>>n>>m;
	//尝试修改下面这个函数
	//memset(cnt,0,sizeof(cnt));
    Init();
	while(m-- > 0)
	{
		int a,b;
		cin>>a>>b;
		Union(a,b);
		//cnt[a]=b;
		//cnt[b]=a;
        //不断合并两个集合的根节点，构建无环树

	}
	//先压缩，再遍历
	for(int x=1;x<=maxn;x++)
	{
		f_f(x);
	}
	for(int x=1;x<=maxn;x++)
	{

		if(father[x]==x)
			ans++;
	}
	cout<<ans<<endl;

	return 0;
 }
