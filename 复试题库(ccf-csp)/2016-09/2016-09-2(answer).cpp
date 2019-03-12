#include<iostream>
#include<map>
using namespace std;
const int N=20;
const int NUM=5;
int main()
{
    map<int,int> m;
    int n,v,st,ed;

    //初始化车厢票源
    for(int i=1;i<=N;i++)
    {
        m[i]=NUM;
    }

    //输入数据,分配车票,输出结果
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        //输入数据：购买火车票张数
        cin>>v;
        //分配车票（同一排分配）并输出结果
        for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
        {
            if(it->second>=v)
            {
                //输出结果
                st=(it->first-1)*NUM+1+(NUM-it->second);
                ed=st+v-1;
                for(int j=st;j<=ed;j++)
                {
                    if(j!=st)
                        cout<<" ";
                    cout<<j;
                }
                cout<<endl;
                //对于票数已经分配完毕的排，删除
                if(it->second==v)
                    m.erase(it);
                else
                    it->second=it->second-v;
                v=0;
                break;
            }
        }
        //分配车票（多排分配）并输出结果
        bool nofirstflag=false;
        while(v>0)
        {
            for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
            {
                if(it->second>=v)
                {
                    //输出结果
                    st=(it->first-1)*NUM+1+(NUM-it->second);
                    ed=st+v-1;
                    for(int j=st;j<=ed;j++)
                    {
                        if(nofirstflag)
                            cout<<" ";
                        cout<<j;
                        nofirstflag=true;
                    }
                    //对于票数已经分配完毕的排，删除
                    if(it->second==v)
                        m.erase(it);
                    else
                        it->second=it->second-v;
                    v=0;
                    break;
                }
                else
                {
                    //输出结果
                    st=(it->first-1)*NUM+1+(NUM-it->second);
                    ed=st+it->second-1;
                    for(int j=st;j<=ed;j++)
                    {
                        if(nofirstflag)
                            cout<<" ";
                        cout<<j;
                        nofirstflag=true;
                    }
                    v=v-it->second;
                    //对于票数已经分配完毕的排，删除
                    m.erase(it);
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
