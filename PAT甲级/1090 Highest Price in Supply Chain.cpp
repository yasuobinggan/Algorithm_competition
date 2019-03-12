//先设置递归主体再设置递归边界
//chain:链子,链条;束缚
//followed by
//dfs:提前处理;当前节点处理
//bfs:解决最短路径
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef struct NODE{
    double price;
    //double amount;
    vector<int> child;
}node;
node chain[maxn];
int N;double P,r;
double maxprice;
int count_r;

void dfs(int index,double price)
{

    if(chain[index].child.size()==0)
    {
        if(price==maxprice)
        {
            count_r++;
        }
        if(price>maxprice)
        {
            maxprice=price;
            count_r=1;

        }

        return;
    }

    for(int i=0;i<chain[index].child.size();i++)
    {
        double curprice;
        curprice=price+price*r;
        dfs(chain[index].child[i],curprice);
    }
}

int main()
{
    scanf("%d",&N);
    scanf("%lf%lf",&P,&r);
    r=(r/100.0);
    vector<int> root;
    for(int i=0;i<N;i++)
    {
        int m;
        scanf("%d",&m);
        if(m!=-1)
        {
            chain[m].child.push_back(i);
        }
        else if(m==-1)
        {
            root.push_back(i);
        }

    }
    for(int i=0;i<root.size();i++)
    {
        double curprice=P+P*r;
        dfs(root[i],curprice);
    }

    printf("%.2f %d",maxprice,count_r);
    return 0;
}
/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
*/
