//模拟事件，不模拟时间
//bool设置优先级是有序的
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int key;//钥匙编号
    int time;//时间
    int flag;//拿or放
    friend bool operator<(Node a,Node b)//种类的优先级从高到低
    {
        if(a.time!=b.time)
            return a.time>b.time;
        else if(a.flag!=b.flag)//先还再取
            return a.flag>b.flag;
        else//钥匙号小的优先
            return a.key>b.key;
    }
};
priority_queue<Node> q;
const int maxn=1005;
int main()
{
    int N,K,w,s,c;
    cin>>N>>K;
    int box[maxn];
    //初始化
    for(int i=1;i<N+1;i++)
        box[i]=i;
    //
    Node event1;
    Node event2;
    //输入压入队列
    for(int i=0;i<K;i++)
    {
        cin>>w>>s>>c;
        //拿钥匙
        event1.key=w;
        event1.time=s;
        event1.flag=1;
        q.push(event1);
        //放回钥匙
        event2.key=w;
        event2.time=s+c;
        event2.flag=-1;
        q.push(event2);
    }
    //模拟事件
    Node temp;
    while(!q.empty())
    {
        temp=q.top();
        q.pop();
        //模拟拿钥匙
        if(temp.flag==1)
        {
            int j=1;
            while(box[j]!=temp.key)
                j++;
            box[j]=0;
        }
        //模拟放钥匙
        else
        {
            int j=1;
            while(box[j]!=0)
                j++;
            box[j]=temp.key;
        }
    }
    //输出
    for(int i=1;i<=N;i++)
        cout<<box[i]<<" ";
    return 0;
}
