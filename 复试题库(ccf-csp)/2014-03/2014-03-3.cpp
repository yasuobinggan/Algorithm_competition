//模拟
//分割字符串(处理字符串中的空格)
#include<bits/stdc++.h>
using namespace std;
const int maxn=26;
const int INF=(1<<30)-1;
string input;
int N;
struct Node{
    bool flag;
    bool par;//参数
};
//输入标志
Node visited_in[maxn];
//输出标志(一个输入字符串一个输出标志(内容为参数值))
struct _Node{
    bool flag;
    string par;
};
//存储最后输出的参数值
_Node visited_out[maxn];
void init_visited_out()
{
    for(int i=0;i<maxn;i++)
    {
        visited_out[i].flag=false;
    }

}
int main()
{
    cin>>input;
    cin>>N;

    //预处理
    memset(visited_in,false,sizeof(visited_in));
    for(int i=0;i<input.size();i++)
    {
        if(input[i]!=':')
        {
            visited_in[input[i]-'a'].flag=true;//有字母选项
            if(input[i+1]==':')
            {
                visited_in[input[i]-'a'].par=true;//有参数
            }
        }
        else
            continue;
    }

    getchar();
    //模拟
    string sten;//输入
    vector<string> curans;
    for(int i=1;i<=N;i++)
    {
        init_visited_out();
        getline(cin,sten);
        //空格处理
        string cur;
        int pos=0;//记录上一个空格的下一个位置
        ///错误的处理
        for(int j=0;j<sten.size();j++)
        {
            if(sten[j]!=' ')
            {
                cur+=sten[j];
                curans.push_back(cur);
            }
            else
                cur="";
        }

        //对每个选项匹配
        for(int k=1;k<curans.size();k++)
        {
            if(curans[k][0]=='-')
            {
                if(visited_in[curans[k][1]-'a'].flag==true)
                {
                    visited_out[curans[k][1]-'a'].flag=true;
                    if(visited_in[curans[k][1]-'a'].par==true)
                    {
                        visited_out[k].par=curans[k+1].substr(1);
                    }
                }
            }
            else
                break;
        }

        //输出
        cout<<"Case "<<i<<":";
        for(int k=0;k<maxn;k++)
        {
            if(visited_out[k].flag==true)
            {
                char c='a'+k;
                cout<<" -"<<c;
                if(visited_in[k].par==true)
                {
                    cout<<" "<<visited_out[k].par;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
albw:x
4
ls -a -l -a documents -b
ls
ls -w 10 -x -w 15
ls -a -b -c -d -e -l
*/
