//integerÕûÊı
#include<bits/stdc++.h>
using namespace std;
char A[64],B[64],C[64];
char res[64];
int main()
{
    int T;
    for(int i=1;i<=T;i++)
    {
        memset(C,'0',sizeof(C));
        memset(res,'0',sizeof(res));
        cin>>A>>B>>C;

        cout<<"Case #"<<i<<": ";
        if(memcmp(res,C,sizeof(C)))
        {
            cout<<"true"<<endl;
        }
        else
            cout<<"false"<<endl;
    }
    return 0;
}
