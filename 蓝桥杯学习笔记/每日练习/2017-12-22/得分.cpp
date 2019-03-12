#include<stdio.h>
#include<string.h>
#define max_length 81
int main()
{
	int count=0,sum=0,i=0;
	char d[max_length]="ooxxoxoooxxooooooxoooxo";
	while(d[i]!='\0')
	{
		/*
		if(d[i]=='o')
			count++;
		else
			count=0;
		*/
		d[i]=='o'?count++:count=0;
		sum+=count;
		//putchar(d[i]);
		i++;
	 }
	printf("%d",sum); 
	return 0;
}
