#include<stdio.h>
int main()
{
	int n,m,k1,x,y;
	long long k;
	long long max,min,c;
	int length;
	while(scanf("%d%d%d%d%d",&n,&m,&k1,&x,&y)==5)
	{
		k=k1;
		max=min=c=0;
		length=n*m;
		if(n==1)
		{
			if(k%length!=0)
				max++;
			max+=k/length;
			min+=k/length;
			if((x*y)>k%length)
				c=min;
			else
				c=max;
		}
		else
		{
			k-=length;
			max=min=1;
			length-=m;
			if(k%length!=0)
				max++;
			max+=k/length;
			min+=k/length;
			if((k/length)%2==0)
			{
				if((x-1*y+y)<=(k%length))
					c=max;
				else
					c=min;
			}	
			else
			{
				if(((m*n)-(x-1*y+y))<=(k%length))
					c=max;
				else
					c=min;
			}
				
		}
		printf("%I64d %I64d %I64d\n",max,min,c);
	}
	return 0;
}