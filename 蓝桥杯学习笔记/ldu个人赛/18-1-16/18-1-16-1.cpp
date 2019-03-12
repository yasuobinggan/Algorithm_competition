#include<stdio.h>
#define m_l 50
int main()
{
	int lab[m_l][m_l];
	int row[m_l], colum[m_l];
	int n, i, j, k, k1, r, r1;
	int flag = 0;
	int count, count1;
	while (scanf("%d", &n) == 1&&n)
	{
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
				scanf("%d", &lab[i][j]);
		}
		count = count1 = 0;
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				if (lab[i][j] != 1)
				{
					count++;
					k1 = 0; r1 = 0;
					for (k = 0; k<n; k++)
					{
						if (k != j)
						{
							row[k1] = lab[i][k];
							k1++;
						}
					}
					for (r = 0; r<n; r++)
					{
						if (r != i)
						{
							colum[r1] = lab[r][j];
							r1++;
						}
					}
					flag = 0;
					for (k = 0; k<n - 1; k++)
					{
						for (r = 0; r<n - 1; r++)
						{
							if ((row[k] + colum[r]) == lab[i][j])
							{
								count1++;
								flag = 1;
								break;
							}
						}
						if (flag == 1)
							break;
					}
					
				}
	
			}//forj
			
		}//fori
		if (count!=count1)
			printf("NO\n");
		else
			printf("YES\n");
	}


	return 0;
}
