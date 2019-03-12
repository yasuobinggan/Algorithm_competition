//unordered_map
//c++中定义同名string变量实际上不同
#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,vector<string>> ans;
void prostring(string &value)
{

}
int main()
{
    cin>>n>>m;
    getchar();
    string input;
    string input_sum;
    for(int i=1;i<=n;i++)
    {
        getline(cin,input);
        input_sum+=input;
    }
    //处理输入字符串空格
    string tar;
    for(int i=0;i<=n;i++)
    {
        if(input_sum[i]!=' ')
            tar+=input_sum[i];
    }
    //cout<<tar<<endl;

    //字符串处理
    int j;
    //内部应该是递归处理
    for(int i=1;i<=tar.size()-2;)
    {
        string key;
        vector<string> val;
        string value;
        j=i;
        while(j!=':')
        {
            if(tar[j]!='"')
            {
                key+=input_sum[j];
            }
            j++;
        }

        if(tar[j]=='{')
        {
            if()
        }
        else
        {

        }
        while(j!=',')
        {
            j++;
        }
        i=j+1;
    }

    //查询操作
    string stext;
    for(int i=1;i<=m;i++)
    {

    }
    return 0;
}
