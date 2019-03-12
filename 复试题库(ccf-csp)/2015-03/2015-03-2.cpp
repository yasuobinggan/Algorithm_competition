//比较器定义时无需分先后顺序，分清情况即可
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
struct Node{
    int value;
    int weight;
    /*
    Node(int value,int weight)
    {
        this.value=value;
        this.weight=weight;
    }
    */
};
Node val[maxn];
int n;
/*
bool cmp(Node a,Node b)
{
    if(a.weight==b.weight)
        return a.value<b.value;
    else
        return a.weight>b.weight;
}
*/
bool cmp(Node a,Node b)
{
    if(a.weight!=b.weight)
        return a.weight>b.weight;
    else
        return a.value<b.value;
}
int main()
{
    cin>>n;
    int v;
    //初始化
////    for(int i=0;i<maxn;i++)
////    {
////        val[i].weight=0;
////    }
    memset(val,0,sizeof(val));
    for(int i=0;i<n;i++)
    {
        cin>>v;
        val[v].value=v;

        val[v].weight++;
    }
    sort(val,val+maxn,cmp);
    int i=0;
    while(val[i].weight!=0)
    {
        cout<<val[i].value<<" "<<val[i].weight<<endl;
        i++;
    }
    return 0;
}
/*
12
5 2 3 3 1 3 4 2 5 2 3 5
*/
