#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p,*q;
	int *o;
	printf("%d\t%d\n",p,q);
	printf("%d\t%d\n",&p,&q);
	
	q=p=(int *)malloc(10*sizeof(int));
	
	printf("%d\t%d\n",p,q);
	printf("%d\t%d\n",&p,&q);
	
	free(q);
	//free(o);
	return 0;
} 