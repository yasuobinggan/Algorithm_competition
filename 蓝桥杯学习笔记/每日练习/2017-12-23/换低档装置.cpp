#include<stdio.h>
#define max_length 100
int main()
{
	int a1[max_length],a2[max_length],n1,n2;
	int i=0,j=0;
	int c1[max_length],c2[max_length],c1_length=0,c2_length=0;
	scanf("%d%d",&n1,&n2);
	/*
	while(i<n1)
		 scanf("%d",&a1[i++]);
	while(j<n2)
		scanf("%d",&a2[j++]);
	*/
	for(i=0;i<n1;i++)
		scanf("%d",&a1[i]);
	for(i=0;i<n2;i++)
		scanf("%d",&a2[i]);
	c1[c1_length]=1;c2[c2_length]=1;
	for(i=1;i<n1;i++)
	{
		if(a1[i]==a1[i-1])
			++c1[c1_length];
		else
		{
			c1[++c1_length]=1;
		}		
	}
	 for(i=1;i<n2;i++)
	{
	 	if(a2[i]==a2[i-1])
			++c2[c2_length];
		else
		{
			c2[++c2_length]=1;
		}
	}
	for(i=0;i<n1;i++)
		printf("%d ",a1[i]);
	for(i=0;i<=c1_length;i++)
		printf("%d ",c1[i]); 
	return 0;
}
