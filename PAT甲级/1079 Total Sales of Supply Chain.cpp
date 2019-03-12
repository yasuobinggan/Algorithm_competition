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
    double amount;
    vector<int> child;
}node;
node chain[maxn];
int N;double P,r;
double totalprice=0;
/*
void dfs(int index,double price)
{
    double curprice;
    if(index==0)
    {
        curprice=P;
    }
    if(index!=0)
    {
        curprice=price+price*(r/100.0);
    }
    if(chain[index].amount!=0)
    {
        totalprice+=chain[index].amount*price;
        return;
    }


    for(int i=0;i<chain[index].child.size();i++)
    {
        dfs(chain[index].child[i],curprice);
    }
}
*/

void dfs(int index,double price)
{

    if(chain[index].amount!=0)
    {
        totalprice+=chain[index].amount*price;
        return;
    }

    for(int i=0;i<chain[index].child.size();i++)
    {
        double curprice;
        curprice=price+price*(r/100.0);
        dfs(chain[index].child[i],curprice);
    }
}

int main()
{
    scanf("%d",&N);
    scanf("%lf%lf",&P,&r);

    //printf("\n%f %f\n",P,r);

    for(int i=0;i<N;i++)
    {
        int k;
        scanf("%d",&k);
        //零售商
        if(k==0)
        {
            double a;
            scanf("%lf",&a);
            chain[i].amount=a;
        }
        //别的
        else
        {
            for(int j=0;j<k;j++)
            {
                int c;
                scanf("%d",&c);
                chain[i].child.push_back(c);
                chain[i].amount=0;
            }
        }
    }

    dfs(0,P);
    printf("%.1f",totalprice);
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
