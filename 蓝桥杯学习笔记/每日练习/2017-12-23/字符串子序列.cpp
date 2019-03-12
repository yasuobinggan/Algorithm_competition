#include<stdio.h>
#include<string.h>
#define max_length 100
int main()
{
	char s[max_length],t[max_length];
	int i=0,j=0;
	while(scanf("%s%s",s,t)!=EOF)
	{
		while(i<strlen(s))
		{
			if(t[j]==s[i])
				j++;
			i++;
		}
		if(j==strlen(t))
			printf("t是s的子序列");
		else
			printf("t不是s的子序列");
	}
	return 0;
}
