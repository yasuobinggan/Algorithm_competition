#include<stdio.h>
#include<stdlib.h>
#define m_l 10
/**
n<=10
1<=a,b<=5
*/
int judge(int t[m_l][m_l], int length[], int p[], int n)
{
	int k, i, j; int sum1, sum2;
	int p1[m_l];//预处理数组 
	for (k = 0; k<1000; k++)
	{
		for (j = 0; j<n; j++)
		{
			printf("%d\t", t[j][p[j]]);
		}
		printf("\n");
		sum1 = 0;
		for (i = 0; i<n; i++)
			sum1 += t[i][p[i]];
		if (sum1 == 0)
			break;
		for (i = 0; i<n; i++)
		{
			if (t[i][p[i]] == 0 && t[i][(p[i] + 1)%length[i]] == 1)
			{
				sum2 = 0;
				for (j = 0; j<n; j++)
				{
					if (t[j][p[j]] == 1)
						sum2++;
				}
				if (sum2>(n - sum2))
					p1[i] = (p[i]+1) % length[i];
					//p[i] = (p[i]+1) % length[i];
				else
					p1[i] = 0;
					//p[i] = 0;
			}
			else
				p1[i] = ((p[i]+1) % length[i]);
				//p[i] = ((p[i]+1) % length[i]);
		}
		for(i=0;i<n;i++)
			p[i]=p1[i];
	}
	if (k == 1000)
		return -1;
	return k + 1;
}
int main()
{
	int n;
	int s[m_l][m_l], t[m_l][m_l];
	int length[m_l], p[m_l];//length保存长度,p保存下标 
	int i, j;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<3; j++)
		{
			scanf("%d", &s[i][j]);
		}
	}
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<s[i][0]; j++)
			t[i][j] = 0;
		for (; j<s[i][0] + s[i][1]; j++)
			t[i][j] = 1;
		length[i] = s[i][0] + s[i][1];
		p[i] = s[i][2] - 1;
	}
	printf("%d\n", judge(t, length, p, n));
	//print_t(t,n,m_l); 
	return 0;
}