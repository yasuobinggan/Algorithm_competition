#include<stdio.h>
#include<string.h>
#define max_length 10000
int main()
{
	int n,i=0,t[10]={0,0,0,0,0,0,0,0,0,0};
	char s[max_length];
	
	while(scanf("%d",&n)!=EOF)
	{
		while(n>0)
		{
			sprintf(s,"%d",n);
			n--;
		}
		puts(s);
		/*
		while(i<strlen(s))
		{
			t[s[i]-'0']++;
			i++;
		}
		*/
		
		while(i<10)
		{
			printf("%d ",t[i++]);
		}
		
		
	}
	return 0;
 } 
