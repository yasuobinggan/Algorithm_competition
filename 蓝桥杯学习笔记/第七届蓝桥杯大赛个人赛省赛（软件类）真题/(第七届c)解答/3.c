#include<stdio.h>
int main()
{
	int a,b,c;
	int d,e,f;
	int g,h,i;
	int sum,w=0;
	int sum1=0,sum2=0;
	for(a=1;a<=9;a++)
	{
		for(b=1;b<=9;b++)
		{
			if(b!=a)
			for(c=1;c<=9;c++)
			{
				if(c!=a&&c!=b)
				sum=0;
				if((((10*c-a*c-b)%c)==0)&&(((10*c-a*c-b)/c)>0))
				{
					sum=((10*c-a*c-b)/c);
					for(d=1;d<=9;d++)
					{
						if(d!=a&&d!=b&&d!=c)
						for(e=1;e<=9;e++)
						{
							if(e!=a&&e!=b&&e!=c&&e!=d)
							for(f=1;f<=9;f++)
							{
								if(f!=a&&f!=b&&f!=c&&f!=d&&f!=e)
								{
									sum1=0;
									sum1=d*100+e*10+f;
									for(g=1;g<=9;g++)
									{
										if(g!=a&&g!=b&&g!=c&&g!=d&&g!=e&&g!=f)
										for(h=1;h<=9;h++)
										{
											if(h!=a&&h!=b&&h!=c&&h!=d&&h!=e&&h!=f&&h!=g)
											for(i=1;i<=9;i++)
											if(i!=a&&i!=b&&i!=c&&i!=d&&i!=e&&i!=f&&i!=g&&i!=h)
											{
												sum2=0;
												sum2=g*100+h*10+i;
												if(sum*sum2==sum1)
												{
													printf("%d %d %d\t",sum1,sum2,sum);
													w++;
												}
														
											}
											
										}
									}
									
								}	
							}
						} 
					}
						
				}	
			}
		}
	}
	printf("\n%d",w);
	return 0;
}