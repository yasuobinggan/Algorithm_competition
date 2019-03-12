#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define MAX 207
using namespace std;
int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    getchar();//不加getchar,getline会少读入一个字符串
    map<string,string> lsmap;//存放输出结果
    //处理
    for(int i = 0 ;i < n; i++)
    {
        string ls;
        getline(cin, ls);
        int ip = 0;
        while(ip < ls.length() && ls[ip]!=' ')
            ip++;
    	ip++;//设置到参数起始位置
    	lsmap.clear();
        while(ip < ls.length())
        {
            string op = "", ag = "";
            //截取参数
            while(ip < ls.length() && ls[ip] != ' ')
            {
                op += ls[ip];
                ip++;
            }
            ip++;
            //判断参数是否在标准中
            if(op[0] != '-' || op.length() != 2 || str.find(op[1]) == string::npos)
                break;
            //判断参数是否有数字参数
            if(str.find(op.substr(1,1)+':')!= string::npos)
            {
                if(ip >= ls.length()) break;
                while(ip < ls.length() && ls[ip] != ' ')
                {
                    ag += ls[ip];
                    ip++;
                }
                ip++;
            }
            lsmap[op] = ag;
        }
        //输出
        printf("Case %d:",i+1);
    	for(map<string,string>::iterator iter = lsmap.begin(); iter != lsmap.end(); iter++)
    	{

    		cout << " " << iter->first;
			if(iter->second != "")
                cout << " " << iter->second;
    	}
    	cout << endl;
    }
    return 0;
}
