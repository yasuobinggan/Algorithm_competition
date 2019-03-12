#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int INF=1e9;
struct station{
    double price,dis;
}st[maxn];
bool cmp(station a,station b)
{
    return a.dis<b.dis;
}
int main()
{
    int n;
    double Cmax,D,Davg;
    scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&st[i].price,&st[i].dis);
    }
    st[n].price=0;
    st[n].dis=D;
    //按照距离排序
    sort(st,st+n,cmp);

    if(st[0].dis!=0)
    {
        printf("The maximum travel distance = 0.00\n");
    }
    else
    {
        int now=0;
        //总花费,当前油箱量,满油行驶距离
        double ans=0,nowTank=0,MAX=Cmax*Davg;
        //O(n^2)循环
        while(now<n)
        {
            int k=-1;
            double priceMin=INF;
            //当前加油站能到达的距离范围中低于当前油价的加油站
            for(int i=now+1;i<=n&&st[i].dis-st[now].dis<=MAX;i++)
            {
                //如果油价比当前油价低
                if(st[i].price<priceMin)
                {
                    //获取最低油价
                    priceMin=st[i].price;
                    k=i;

                    //(无法到达)如果找到第一个油价低于当前油价的加油站,直接中断循环
                    if(priceMin<st[now].price)
                    {
                        break;
                    }

                }
            }
            //满油状态下无法找到加油站,退出循环输出结果
            if(k==-1)
                break;

            //策略1
            //找可能到达的加油站k，计算转移花费
            //need: now到k需要的油量
            double need=(st[k].dis-st[now].dis)/Davg;
            //存在加油站油价低于当前油价
            if(priceMin<st[now].price)
            {
                //只卖足够到达加油站k的油
                //当前油量不足need
                if(nowTank<need)
                {
                    //补足need后计算油价
                    ans+=(need-nowTank)*st[now].price;
                    //到达后油箱为空
                    nowTank=0;
                }
                //当前油量超过need
                else
                {
                    nowTank-=need;
                }

            }
            //策略2
            //如果加油站k的油价高于当前油价
            else
            {
                //将油箱加满
                ans+=(Cmax-nowTank)*st[now].price;
                //到达加油站k后的油量
                nowTank=Cmax-need;
            }
            now=k;
        }

        if(now==n)
        {
            printf("%.2f\n",ans);
        }
        else
        {
            printf("The maximum travel distance = %.2f\n",st[now].dis+MAX);
        }

    }
    return 0;
}
/*
//大胆贪心尝试
//区间贪心
//贪心往往是第一步
//贪心的是哪一个标尺

//destintation目的,目标
#include<bits/stdc++.h>
using namespace std;
//油箱量，距离，单位油量汽车能走的距离,加油站数量
double C,D,D_a;int N;
const int maxn=505;
typedef struct node{
    double p;
    double sD_c;
    double eD_c;

    double value;
}s;
s station[maxn];
bool vis[maxn];
bool cmpsD_c(s a,s b)
{
    return a.sD_c<b.sD_c;
}
bool cmpeD_c(s a,s b)
{
    return a.eD_c>b.eD_c;
}
int main()
{
    //cin>>C,D,D_a,N;
    scanf("%lf %lf %lf",&C,&D,&D_a);
    scanf("%d",&N);
    double minprice=0;
    double maxlength=0;
    for(int i=0;i<N;i++)
    {
        //输入单位油价，加油站距杭州的距离
        scanf("%lf %lf",&station[i].p,&station[i].sD_c);
        station[i].eD_c=station[i].sD_c+C*D_a;

        //一个标尺衡量价值：剩余距离/单位油价
    }
    sort(station,station+N,cmpsD_c);
    //贪心距离
    //加入lower_bound的查找
    //memset(vis,vis+N,0);
    maxlength=station[0].eD_c;
    minprice+=station[0].p*C;
    for(int i=1;i<N;i++)
    {
        if(maxlength<=station[i].sD_c&&maxlength>station[i-1].eD_c)
        {
            maxlength=station[i-1].eD_c;
            minprice+=station[i-1].p*C;
        }

    }
    if(maxlength>=D)
        printf("%.2f",maxlength);
    else
        printf("The maximum travel distance = %.2f",maxlength);
    //贪心花费
    return 0;
}
*/

