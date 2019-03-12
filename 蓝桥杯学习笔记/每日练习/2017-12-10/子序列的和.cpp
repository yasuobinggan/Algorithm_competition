#include<stdio.h>
int main()
{
	int n,m;
	long long n1,m1;//
	long long i;
	double res;
	n1=n;
	m1=m;
	while(scanf("%d%d",&n,&m)==2&&n&&m)
	{
		res=0;
		for(i=n;i<=m;i++)
		{
			res+=(double)1/(i*i);
		}
		printf("%.5f",res);
	}
	//printf("%d",res);
	return 0;
}
