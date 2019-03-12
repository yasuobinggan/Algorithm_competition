#include<stdio.h>
#include<math.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(fabs(a-b)<=1&&(a!=0||b!=0))
			printf("YES\n");
		else
			printf("NO\n");		
	}
	return 0;
}