#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void process(string input)
{
    string add;

    int st=0;
    while(input[st]==' ')
        st++;
    int ed=input.size()-1;
    while(input[ed]==' ')
        ed--;
    //for(int i=st;i<=ed;i++)
    //    cout<<input[i];
    //cout<<endl;
    for(int i=st;i<=ed;)
    {
        int j=i;
        add.clear();
        while(input[j]!=' '&&j<=ed)
        {
            add+=input[j];
            j++;
        }
        //cout<<"当前加入:"<<add<<endl;
        ans.push_back(add);
        i=j+1;
    }
}
int main()
{
    string input;
    getline(cin,input);
    process(input);
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i];
        if(i!=0)
            cout<<" ";
    }
    return 0;
}
//Hello World Here I Come
