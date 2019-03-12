#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,m;
vector<int> q;
//int q[maxn];
//int f;
//int r;
void testout()
{
    for(int i=0;i<q.size();i++)
        cout<<q[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        q.push_back(i);
    }
    cin>>m;
    int id,op;
    for(int i=1;i<=m;i++)
    {
        cin>>id>>op;
        for(int j=0;j<q.size();j++)
        {
            if(q[j]==id)
            {
                if(op<0)
                {
                    //向前移动(放置)
                    int temp=q[j];
                    int k;
                    for(k=j-1;k>=j+op;k--)
                        q[k+1]=q[k];
                    q[j+op]=temp;
                    //testout();
                    break;
                }
                if(op>0)
                {
                    //向后移动(放置)
                    int temp=q[j];
                    int k;
                    for(k=j+1;k<=j+op;k++)
                        q[k-1]=q[k];
                    q[j+op]=temp;
                    //testout();
                    break;
                }
            }
        }
    }
    //输出
    testout();
    return 0;
}
/*
8
3
3 2
8 -3
3 -2
*/
