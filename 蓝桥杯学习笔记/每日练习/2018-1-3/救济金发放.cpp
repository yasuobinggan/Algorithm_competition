#include<stdio.h>
const int max_l = 20;
bool chu(int a[], int n)
{
	for (int i = 0; i<n; i++)
		if (a[i] != 0)
			return false;
	return true;
}
/*
*/
int main()
{
	int a[max_l];
	int n, k, m;
	int k1, m1;
	scanf("%d%d%d", &n, &k, &m);
	k1 = k - 1; m1 = n - m;
	for (int i = 0; i<n; i++)
		a[i] = i + 1;
	while (!chu(a, n))
	{
		if (k1 != m1)
			printf("%d %d\n", a[k1], a[m1]);
		else
			printf("%d\n", a[k1]);
		a[k1] = a[m1] = 0;

		while(a[((++k1) + n)%n]==0);
		for (int j = 0; j<k;)//多循环一位跳出0 
		{
			if (a[k1] != 0)
				j++;
			k1 = ((++k1) % n);
		}
		k1=((--k1) + n)%n;
		
		while(a[((--m1) + n)%n]==0);
		for (int j = 0; j<m;)
		{
			if (a[m1] != 0)
				j++;
			m1 = (((--m1) + n) % n);
		}
		m1=((++m1) + n)%n;
	}
}
