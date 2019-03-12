//在线查找有序数组中的内容
//先找块,再找块内内容
#include<bits/stdc++.h>
#define maxn 100005
#define sqrN 316
using namespace std;
stack<int>st;
int table[maxn];
int block[sqrN];

void peekMedian(int K)
{
    int sum=0;
    int idx=0;
    while(sum+block[idx]<K)
    {
        sum+=block[idx++];
    }
    int num=idx*sqrN;
    while(sum+table[num]<K)
    {
        sum+=table[num++];
    }
    printf("%d\n",num);
}
void Push(int x)
{
    st.push(x);
    block[x/sqrN]++;
    table[x]++;
}
void Pop()
{
    int x=st.top();
    st.pop();
    block[x/sqrN]--;
    table[x]--;
    printf("%d\n",x);
}

int main()
{
    int x,query;
    memset(table,0,sizeof(table));
    memset(block,0,sizeof(block));
    char cmd[20];
    scanf("%d",&query);
    for(int i=0;i<query;i++)
    {
        scanf("%s",cmd);
        if(strcmp(cmd,"Push")==0)
        {
            scanf("%d",&x);
            Push(x);
        }
        else if(strcmp(cmd,"Pop")==0)
        {
            if(st.empty()==true)
            {
                printf("Invalid\n");
            }
            else
            {
                Pop();
            }
        }
        else
        {
            if(st.empty()==true)
            {
                printf("Invalid\n");
            }
            else
            {
                int K=st.size();
                if(K%2==1)
                    K=(K+1)/2;
                else
                    K=K/2;
                peekMedian(K);
            }
        }
    }
    return 0;
}
