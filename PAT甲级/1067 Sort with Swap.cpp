//反向打表
//打表思想
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int pos[maxn];
int main()
{
    //ans表示总交换次数
    int n,ans=0;
    scanf("%d",&n);
    //left存放除0以外不再本位上的数的个数
    int left=n-1,num;
    //输入
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        //num的位置为i
        pos[num]=i;
        //如果除0以外有在本位上的数
        if(num==i&&num!=0)
        {
            left--;
        }
    }
    //k存放除0以外有不在本位上的最小的数
    int k=1;
    while(left>0)
    {
        //0在本位上
        //寻找一个当前不在本位上的数与0交换
        if(pos[0]==0)
        {
            while(k<n)
            {
                //找到一个当前不在本位上的数k
                if(pos[k]!=k)
                {
                    swap(pos[0],pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        //0不在本位
        //
        while(pos[0]!=0)
        {
            swap(pos[0],pos[pos[0]]);
            ans++;
            left--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
