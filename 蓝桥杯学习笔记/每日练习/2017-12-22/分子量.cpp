#include<stdio.h>
#include<string.h>
#include<cctype>
#define max_length 50
int main()
{
	char fenzi[max_length];
	int i=0;
	double sumliang=0;
	while(scanf("%s",fenzi)!=EOF)
	{
		while(i<=strlen(fenzi))
		{
			if(!isalpha(fenzi[i+1])&&(i+1)<strlen(fenzi))//问题边界处理 
			{
				switch(fenzi[i])
				{
					case 'c':sumliang+=(fenzi[i+1]-'0')*12.01;break;
					case 'h':sumliang+=(fenzi[i+1]-'0')*1.008;break;
					case 'o':sumliang+=(fenzi[i+1]-'0')*16.00;break;
					case 'n':sumliang+=(fenzi[i+1]-'0')*14.01;break;
				}
				i+=2;
			}
			else
			{
				switch(fenzi[i])
				{
					case 'c':sumliang+=12.01;break;
					case 'h':sumliang+=1.008;break;
					case 'o':sumliang+=16.00;break;
					case 'n':sumliang+=14.01;break;
				}
				i++;
			}
		}
		printf("%.3f",sumliang);
	 } 
	return 0;
}
