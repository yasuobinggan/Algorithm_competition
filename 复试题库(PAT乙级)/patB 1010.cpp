#include<bits/stdc++.h>
using namespace std;
//const int maxn=10005;
struct Node{
    int xi;
    int zi;
    Node(int _xi,int _zi)
    {
        xi=_xi;
        zi=_zi;
    }
};
vector<Node> ml;
//Node ml[maxn];
int main()
{
    int xi,zi;
    while(cin>>xi>>zi)
    {
        if(xi==zi&&xi==0)
        {
            ml.push_back(Node(xi,zi));
            break;
        }
        else if(zi==0)
            break;
        else
            ml.push_back(Node(xi,zi));
    }
    for(int i=0;i<ml.size();i++)
    {
        if(ml[i].xi==0&&ml[i].zi==0)
            cout<<0<<" "<<0;
        else
        {
            cout<<ml[i].xi*ml[i].zi<<" "<<ml[i].zi-1;
        }
        if(i!=ml.size()-1)
            cout<<" ";
    }
    return 0;
}
