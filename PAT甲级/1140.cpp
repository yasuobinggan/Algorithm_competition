//to_string函数
//string头文件 
//hence 从此; 因此，所以; 从此处 

#include<bits/stdc++.h>

using namespace std;
int d, N;
int num[10000], len;
int curnum[10000];
void find(int k)
{
	if (k == N)
	{
		for (int i = 0; i<len; i++)
			cout << num[i];
		return;
	}
	int len1 = 2;//记录这组数的长度
	for (int i = 1; i<len;)
	{
		int j;
		int count;
		count = 0;
		for (j = i; j<len; j++)
		{
			if (num[j] == num[i])
				count++;
			else
				break;
		}
		curnum[len1] = num[i];
		curnum[++len1] = count;
		++len1;
		i = j;
	}
	len = len1;
	memcpy(num, curnum, sizeof(curnum));
	find(k + 1);
}
int main()
{
		cin >> d >> N;
		if (N == 1)
			cout << d;
		else if (N == 2)
			cout << d << "1";
		else
		{
			num[0] = d;num[1] = 1;
			curnum[0] = d;curnum[1] = 1;
			len = 2;

			find(2);
		}
		return 0;
}
