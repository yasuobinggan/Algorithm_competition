#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long m, b;
	long long x;int y;
	long long length,max;
	
	while (scanf("%d%d", &m, &b) == 2)
	{
		max=0;
		length=0;
		for(y=0;y<=b;y++)
		{
			
			x=(b-y)*(m);
			length=(y*(y+1)/2+y*(y+1)/2+(y+1)*x)*(x+1)/2;
			if(length>max)
				max=length;
		}
		printf("%d\n", max);
	}
	return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int m,b;
    scanf("%d%d",&m,&b);
    long long ans = 0,sum = 0;  
    for(int y = 0; y <= b; y++)  
    {  
        long long x = (long long) (b - y)*m; 
        long long sum =  x*(1+x)/2*(1+y)+y*(1+y)/2*(1+x);
        //等差数列求和公式推导 
        ans = max(ans,sum);  
    }  
    cout<<ans<<endl;  
    return 0;
}
*/
