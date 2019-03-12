//检查代码
//两次dfs，多次使用dfs,开空间

#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
char grid[maxn][maxn];
//0未被访问,1不能通过,2访问过
int visited[maxn][maxn],visited1[maxn][maxn];
int R,C;
int dir[4][2]={0,-1,-1,0,0,1,1,0};
int starti,startj,endi,endj;
int ans=0;
vector<int> action(char ins)
{
    vector<int> ans;
    switch(ins)
    {
        case'+':
        case'S':
        case'T':
            ans.push_back(0);ans.push_back(1);ans.push_back(2);ans.push_back(3);
            break;
        case'-':ans.push_back(0);ans.push_back(2);
            break;
        case'|':ans.push_back(1);ans.push_back(3);
            break;
        case'.':ans.push_back(3);
            break;
    }
    return ans;
}
void dfs_j1(int curi,int curj)
{
    visited[curi][curj]=2;
    int ansi,ansj;
    vector<int> ans=action(grid[curi][curj]);
    for(int i=0;i<ans.size();i++)
    {
        ansi=curi+dir[ans[i]][0];
        ansj=curj+dir[ans[i]][1];
        if(ansi>=0&&ansi<=(R-1)&&ansj>=0&&ansj<=(C-1))
        {
            if(grid[ansi][ansj]!='#'&&visited[ansi][ansj]==0)
                dfs_j1(ansi,ansj);
        }
    }
}
//另一种回溯全路径
void dfs_j2(int curi,int curj,bool &flag)
{
    if(flag==true)
        return;
    visited1[curi][curj]=2;
    if(curi==endi && curj==endj)
    {
        flag=true;
        //重点
        visited1[curi][curj]=0;
        return;
    }
    int ansi,ansj;
    vector<int> ans=action(grid[curi][curj]);
    for(int i=0;i<ans.size();i++)
    {
        ansi=curi+dir[ans[i]][0];
        ansj=curj+dir[ans[i]][1];
        if(ansi>=0&&ansi<=(R-1)&&ansj>=0&&ansj<=(C-1))
        {
            if(grid[ansi][ansj]!='#'&&visited1[ansi][ansj]==0)
                dfs_j2(ansi,ansj,flag);
        }
    }
    visited1[curi][curj]=0;
}
void testout(int visited[][maxn])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<visited[i][j];
        }
        cout<<endl;
    }
    cout<<"****************************"<<endl;
}
int main()
{
    cin>>R>>C;
    //scanf("%d %d",&R,&C);
    memset(visited,0,sizeof(visited));
    memset(visited1,0,sizeof(visited1));
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='S')
            {
                starti=i;
                startj=j;
            }
            if(grid[i][j]=='T')
            {
                endi=i;
                endj=j;
            }
            if(grid[i][j]=='#')
            {
                visited[i][j]=1;
                visited1[i][j]=1;
            }
        }
    }

    dfs_j1(starti,startj);

    if(visited[endi][endj]!=2)
    {
        cout<<"I'm stuck";
        return 0;
    }

    bool flag;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if( visited[i][j]==2 && starti!=i && j!=startj )
            {
                flag=false;
                dfs_j2(i,j,flag);
                //testout();
                if(flag==false)
                {
                    //cout<<i<<"  "<<j<<endl;
                    ans++;
                }

            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 5
--+-+
..|#.
..|##
S-+-T
####.
*/
