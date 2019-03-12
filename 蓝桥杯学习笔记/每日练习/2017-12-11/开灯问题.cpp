#include<stdio.h>
#include<math.h>
#define max 100
int a[max];
int main()
{
	int n,k;
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		a[i]=1;//Éè1ÎªÁÁ
	for(i=2;i<=k;i++)
	{
		for(j=0;j<n;j++)
		{
			if((j+1)%i==0)
				a[j]=abs(a[j]-1);
			printf("*%d ",a[j]);
		}
		printf("\n");
	 }
	 for(i=0;i<n;i++)
	 	if(a[i]==1)printf("%d ",i+1); 
	return 0;
}
