#include<stdio.h>
#include<cmath>
int main()
{
	char c;
	int flag=0;
	while((c=getchar())!=EOF)
	//while(scanf("%c",c)!=EOF)
	{
		if(c=='"'&&!flag)
		{
			c='``';
			flag=abs(flag-1);
		} 
		else if(c=='"'&&flag)
		{
			c='++';
			flag=abs(flag-1);
		}
		putchar(c);
	 }
	  
	return 0;
}
