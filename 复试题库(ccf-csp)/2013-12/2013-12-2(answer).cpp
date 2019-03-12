#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int sum=0,j=1;
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]!='-')
        {
            sum+=(s[i]-'0')*j;
            j++;
        }
    }
    //
    char c;
    c=sum%11;
    if(c==10)
        c='X';
    else
        c=c+'0';
    //
    if(c==s[s.length()-1])
        cout<<"Right"<<endl;
    else
    {
        s[s.length()-1]=c;
        cout<<s<<endl;
    }

    return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int val[11];
//    scanf("%d-",&val[1]);
//    for(int i=2;i<=4;i++)
//        scanf("%d",&val[i]);
//    scanf("-");
//    for(int i=5;i<=9;i++)
//        scanf("%d",&val[i]);
//    scanf("-");
//    scanf("%d",&val[10]);
//    int sum=0;
//    for(int i=1;i<=9;i++)
//    {
//        sum+=i*val[i];
//    }
//    if(sum%11==val[10])
//        printf("Right");
//    else
//    {
//        printf("%d-",val[1]);
//        for(int i=2;i<=4;i++)
//            printf("%d",val[i]);
//        printf("-");
//        for(int i=5;i<=9;i++)
//            printf("%d",val[i]);
//        printf("-");
//        printf("%d",val[10]);
//
//    }
//    return 0;
//}
