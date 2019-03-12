#include<stdio.h>
int f(int n)
{
	if(n==1||n==2)return 1;
	else return f(n-1)+f(n-2);
}
int main()
{
	int n;
	scanf("%d",&n);
	if(f(n)>10007)
	printf("%d",f(n)%10007);
}
