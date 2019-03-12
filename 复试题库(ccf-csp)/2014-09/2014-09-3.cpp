#include<bits/stdc++.h>
using namespace std;
//ÊÖĞ´ĞŞ¸Ä×Ö·û´óĞ¡Ğ´
string M_tolower(string input)
{
    string output;
    for(int i=0;i<input.size();i++)
    {
        output+=tolower(input[i]);
    }
    return output;
}
int main()
{
    string strd;
    cin>>strd;
    int flag;
    cin>>flag;
    int n;
    cin>>n;

    string input;
    if(flag==0)
    {
        strd=M_tolower(strd);
        //cout<<"²âÊÔÊä³ö"<<output<<endl;
        for(int i=1;i<=n;i++)
        {
            cin>>input;
            string output=M_tolower(input);
            //cout<<"²âÊÔÊä³ö"<<output<<endl;
            if(output.find(strd)!=string::npos)
            {
                cout<<input<<endl;
            }
        }
    }
    else
    {
        //M_tolower(strd);
        for(int i=1;i<=n;i++)
        {
            //string output=M_tolower(input);
            cin>>input;
            if(input.find(strd)!=string::npos)
            {
                cout<<input<<endl;
            }
        }
    }
    return 0;
}
/*
Hello
0
5
HelloWorld
HiHiHelloHiHi
GrepIsAGreatTool
HELLO
HELLOisNOTHello
*/
