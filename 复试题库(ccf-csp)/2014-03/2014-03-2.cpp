//模拟
//STL队列不能遍历
#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int N,M;
struct Node{
    int x1;int y1;
    int x2;int y2;
    int num;
    //int flag;//标记是否被点击:1点击,0未被点击
};
Node q[maxn];
void testout()
{
    cout<<"测试输出:"<<endl;
    for(int i=1;i<=N;i++)
    {
        cout<<q[i].num<<" ";
    }
    cout<<endl;
}
int main()
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        Node node;
        cin>>node.x1>>node.y1>>node.x2>>node.y2;
        node.num=i;
        //node.flag=0;
        q[i]=node;
        //q.push(node);
    }
    //模拟
    int px,py;
    for(int i=1;i<=M;i++)
    {
        cin>>px>>py;
        int j;
        for(j=N;j>=1;j--)
        {
            if(q[j].x1<=px&&px<=q[j].x2&&q[j].y1<=py&&py<=q[j].y2)
            {
                //cout<<"当前棋盘:"<<q[j].num;
                Node temp=q[j];
                //后半部分前移
                for(int k=j+1;k<=N;k++)
                {
                    q[k-1]=q[k];
                }
                q[N]=temp;
                //testout();
                cout<<q[N].num<<endl;
                break;
            }
        }
        if(j==0)
            cout<<"IGNORED"<<endl;
    }
    return 0;
}
