#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int maxn = 1005;

int posnum[maxn], negnum[maxn];
int n;
int vert(int value)
{
	return 0 - value;
}

void testout()
{
    cout<<"************************";
    cout<<endl<<"负数列"<<endl;
    for(int i=1;i<=10;i++)
    {
        cout<<negnum[i]<<" ";
    }

    cout<<endl<<"正数列"<<endl;
    for(int i=1;i<=10;i++)
    {
        cout<<posnum[i]<<" ";
    }
    cout<<endl<<"************************"<<endl;
}
int main()
{
	memset(posnum, 0, sizeof(posnum));
	memset(negnum, 0, sizeof(negnum));

	cin >> n;
	int ans = 0;
	int value;
	for (int i = 0; i<n; i++)
	{
		cin >> value;

		if (value >= 0 && negnum[value] != 0)
		{
			negnum[value]--;
			ans++;
			//cout<<"负减少："<<negnum[value]<<" ";
			//cout<<"当前结果："<<ans<<endl;
			//testout();
		}
		else if (value >= 0 && negnum[value] == 0)
		{
			posnum[value]++;
			//cout<<"正增加："<<posnum[value]<<endl;
			//testout();
		}
		else if (value<0 && posnum[vert(value)] != 0)
		{
			posnum[vert(value)]--;
			ans++;
			//cout<<"正减少："<<posnum[vert(value)]<<" ";
			//cout<<"当前结果："<<ans<<endl;
			//testout();
		}
		else if (value<0 && posnum[vert(value)] == 0)
		{
			negnum[vert(value)]++;
			//cout<<"负增加："<<negnum[vert(value)]<<endl;
			//testout();
		}
	}
	cout << ans;
	return 0;
}


/*
11
-1 1 -1 -1 1 2 -2 3 4 5 -3
*/
