//！队列方式解决 
#include<stdio.h>
#include<math.h>
#define max 100
int h_digit(int value)
{
	while(value>10)
	{
		value/=10;
	}
	return value;
}
int digit(int value)//获取数的位数 
{
	int i=0;
	while(value>0)
	{
		value/=10;
		i++;
	}
	return i;
}
int fac(int a)
{
	int num=1;
	while(a>0)
	{
		num*=10;
		a--;
	}
	return num;
}
int half(int n)
{
	return n/2;
}
void halfset(int v[],int value,int &length)
{
	//int i;
	int j;
	//printf("%d",fac(digit(value)));
	
		for(j=1; j<=half(h_digit(value)) ;j++)
		{
			v[length]=(j*fac(digit(value))+value);
			length++;
			//printf("\t%d",j*fac(digit(value))+value);
			halfset(v,v[length-1],length);
		}
	
	
		
}
int main()
{
	int value,v[max],length;
	int i;
	scanf("%d",&value);//输入数字创建半数集 
	v[0]=value;length=1;
	halfset(v,value,length);
	//printf("%d\n",length);
	
	printf("\n输出数组:\n");
	for(i=0;i<length;i++)
	{
		printf("%d\t",v[i]);
	 }
	  
	return 0;
 }
 
