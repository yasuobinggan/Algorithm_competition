#include<stdio.h>
#include<string.h>
#define m_l 100
int main()
{
	char str[m_l];
	int c[4];
	int r,b,y,g;
	while(scanf("%s",str)!=EOF)
	{
		
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]=='R')
			{
				r=i%4;
			}
			if(str[i]=='B')
			{
				b=i%4;	
			}
			if(str[i]=='Y')
			{
				y=i%4;
			}
			if(str[i]=='G')
			{
				g=i%4;	
			}
			if(str[i]=='!')
			{
				c[i%4]++;
			}
		}
		printf("%d %d %d %d\n",c[r],c[b],c[y],c[g]);			
	}
	return 0;
}