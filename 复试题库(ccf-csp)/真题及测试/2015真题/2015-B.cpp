#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin>>input;
    for(int i=0;i<input.size();)
    {
        int j=i;
        int cnt=0;
        while(input[j]==input[i])
        {
            cnt++;
            j++;
        }
        cout<<input[i]<<cnt;
        i=j;
    }
    return 0;
}
