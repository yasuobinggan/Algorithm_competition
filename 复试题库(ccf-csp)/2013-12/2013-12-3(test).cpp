#include<bits/stdc++.h>
using namespace std;

const int N=1005;
int h[N+1];

int main()
{
    int n,ans=0,area,temp;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>h[i];
    h[n]=0;
    //计算最大矩形面积
    return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1005;
//int val[maxn];
//int main()
//{
//    int maxarea=-1,maxhigh=-1;//,maxwidth=0;
//    int curarea=0,curhigh=0,curwidth=0;
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        cin>>val[i];
//        if(val[i]>maxhigh)
//        {
//            if(maxhigh>maxarea)
//            {
//                curwidth=1;
//                maxhigh=val[i];
//                curarea=maxhigh*curwidth;
//            }
//            else
//            {
//                //maxhigh=val[i];
//                curwidth++;
//                curarea=maxhigh*curwidth;
//            }
//            if(curarea>maxarea)
//            {
//                maxarea=curarea;
//            }
//        }
//        else if(val[i]<maxhigh)
//        {
//            if((curwidth+1)*val[i]>maxarea)
//        }
//        else
//        {
//            maxarea+=maxhigh;
//            curwidth++;
//        }
//    }
//    cout<<maxarea;
//    return 0;
//}
