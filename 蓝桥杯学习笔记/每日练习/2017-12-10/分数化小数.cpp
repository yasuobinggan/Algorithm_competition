#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	int i;
	double result;int result1;
	while(scanf("%d%d%d",&a,&b,&c)==3&&a&&b&&c)
	{
		/*
		result=(double)a/b;
		result/=pow(0.1,c);
		printf("0.%d",(int)floor(result+0.5));
		*/
		result=(double)a/b;
		result*=pow(10,c);
		result1=floor(result+0.5);
		printf("0.%d",result1);
		//printf("0.%d",(int)floor(result+0.5));//！esult为循环小数造成floor返回值出错 
	 }
	  
	return 0;
}
