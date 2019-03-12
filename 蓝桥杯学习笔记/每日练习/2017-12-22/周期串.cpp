#include<stdio.h>
#include<string.h> 
#define max_length 80
int main()
{
	char s[max_length];
	int flag=0,i=1,j,count=0;
	while(scanf("%s",s)!=EOF)
	{
		i=1;
		while(i<strlen(s))
		{
			if((s[i]==s[0]) && (strlen(s)%i==0))
			//if(strlen(s)%i==0)
			{
				j=i;
				while(j<strlen(s))
				{
					if(s[j]==s[j%i])
						flag=1;
					else
					{
						flag=0;
						break;
					}
					j++;
				}
			}
			if(flag)
			{
				//i==1?printf("%d",strlen(s)):printf("%d",i);
				printf("%d",i);
				break;
			}	
			i++;
		}
		//if(!flag)
			
		//count==0?printf("%d",strlen(s)):printf("%d",count);
	}
	return 0;
 } 
