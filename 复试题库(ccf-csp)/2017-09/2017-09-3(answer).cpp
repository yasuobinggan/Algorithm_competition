#include<iostream>
#include<cstring>
#include<map>
using namespace std;
const int maxn = 100+5;
map<string,string> dic;
char in[maxn*maxn];

int solve(char *key,char *a)
{//处理的字符串的长度
    for(int i=0;i<strlen(a);i++)
    {
        char nowKey[maxn],value[maxn];
        int lenKey = strlen(key);
        int k=0;
        for(k=0;k<lenKey;k++)
            nowKey[k] = key[k];
        nowKey[k] = '\0';
        if(lenKey > 0)
        {
            nowKey[lenKey++] = '.';
            nowKey[lenKey] = '\0';
        }
        if(a[i] == '"')//key的第一个引号
        {
            i++;
            while(a[i] != ':')
            {
                nowKey[lenKey++] = a[i++];
            }
            nowKey[lenKey-1] = '\0';
         }
         //i++;//：
         i++;//"或是｛
         if(a[i] == '"'){
             ///得到value的值，建立map
             int j=7;
             i++;
             strcpy(value,"STRING ");
             while(a[i] != ',' && a[i] != '}'){
                 value[j++] = a[i++];
             }
             value[j-1] = '\0';
             dic[nowKey] = value;
         }else if(a[i] == '{')
         {
              ///首先存储nowKey到map中
             dic[nowKey] = "OBJECT";
             i += solve(nowKey,a+i+1)+1;
          }
          //i++;//，或是}
          if(a[i] == '}')
              return i+1;
           //如果是，则继续处理
    }
}

int main()
{
    string str;
    int n,m;
    cin>>n>>m;
    n = n+1;
    int i=0;
    while(n--)
    {///除了字符串内部的位置，其他位置都可以插入一个或多个空格使得 JSON 的呈现更加美观，
    ///也可以在一些地方换行，不会影响所表示的数据内容。
    ///为了处理掉多余的空格和换行，我将输入数据存储到一个一维的char数组中
        getline(cin,str);
        ///将读入的字符串先进行处理，存储到字符数组中
        for(int k=0;k<str.length();k++)
        {
            if(str[k]=='\\')
                in[i++] = str[++k];
            else if(str[k] == ' ' || str[k] == '\n')
                continue;
            else{
                in[i++] = str[k];
            }
         }
    }
    in[i] = '\0';
    solve("",in+1);//处理第一层嵌套

    for(int j=0;j<m;j++)
    {
        string str2;
        getline(cin,str2);
        map<string,string>::iterator iter = dic.find(str2);
        if(iter != dic.end())
        {//找到了
            cout<<dic[str2]<<endl;
        }else{
            cout<<"NOTEXIST"<<endl;
        }
    }
    //printf("%s\n",in);
    return 0;
}
