#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin>>input;
    int i=0;
    while(i<input.size())
    {
        if(0<=input[i]-'a'&&input[i]-'a'<=26)
        {
            int j=i+1;
            int cal=0;
            while(0<=input[j]-'0'&&input[j]-'0'<=9)
            {
                cal*=10;
                cal+=input[j]-'0';
                j++;
            }
            //cout<<cal<<endl;
            if(cal==0)
                cout<<input[i];
            for(int w=1;w<=cal;w++)
            {
                cout<<input[i];
            }
            i=j;

        }
    }
    cout<<endl;
    return 0;
}
/*
a5b3aba13b4
*/
