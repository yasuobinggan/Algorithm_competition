#include<iostream>
#include<stdio.h>
#include<string.h>
#define max_length 1000

using namespace std;
int main()
{
	char a[max_length],b[max_length];
	while(gets(a)&&gets(b))
	{
		if(strcmp(a,b)==0)
			printf("-1\n");
		//if(strlen(a)==0||strlen(b)==0)
		//	printf("-1\n"); 
		else
			printf("%d\n",strlen(a)>=strlen(b)?strlen(a):strlen(b)); 
	}
	return 0;	
}