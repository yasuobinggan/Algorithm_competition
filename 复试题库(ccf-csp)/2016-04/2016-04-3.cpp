#include<bits/stdc++.h>
using namespace std;
int p;
string fix(string input)
{
    string output;
    for(int i=0;i<input.size();)
    {
        int j=i;
        while(input[j]=='.')
            j++;
        if(input[j]=='/')
        {
            output+='/';
            j++;
            while(input[j]=='/'||input[j]=='.')
                j++;
            i=j;
        }
        else
        {
            output+=input[i];
            i++;
        }
    }
    return output;
}
int main()
{
    cin>>p;
    string cur;
    string input;
    cin>>cur;
    for(int i=1;i<=p;i++)
    {
        cin>>input;
        string output=fix(input);
        cout<<output<<endl;
    }
    return 0;
}
