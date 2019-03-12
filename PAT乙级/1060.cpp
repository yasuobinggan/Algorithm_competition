#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int c_l, l[100005];
int m_n;
bool cmp(int a,int b)
{
	return a>b;
 } 
int main()
{
	while (cin >> c_l)
	{
		m_n = 0;
		for (int i = 0; i<c_l; i++)
			cin >> l[i];	
		sort(l, l + c_l,cmp);
		
		for (int i = 0; i<c_l; i++)
		{	
			if (l[i]<=i+1)
			{
				cout<<i<<endl;
				break;
			}		
		}
	}
	return 0;
}
