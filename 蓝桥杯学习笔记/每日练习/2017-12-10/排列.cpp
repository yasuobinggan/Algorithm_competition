#include<stdio.h>
int main()
{
	int a,b,c;
	int d,e,f,g,h,i;
	//int i;
	int result,result1,result2;
	/*
	for(a=1;a<=3;a++)
	{
		//result=0;
		for(b=1;b<=9;b++)
		{
			if(b!=a)
			for(c=1;c<=9;c++)
			{
				if(c!=a&&c!=b)
				{
					result=a*100+b*10+c;
					result1=result*2;
					result2=result*3;
					//result=(result*2)/100;
					d=result1/100;
					result1%=100;
					e=result1/10;
					result1%=10;
					f=result1;
					if(d==e||d==f||e==f)
						continue; 
					g=result2/100;
					result2%=100;
					h=result2/10;
					result2%=10;
					i=result2;
					if(g==h||g==i||h==i)
						continue;
					
				}		
			}
		}
	 }
	 */
	for(a=1;a<=9;a++)
	{
		for(b=1;b<=9;b++)
		{
			if(b!=a)
			for(c=1;c<=9;c++)
			{
				if(c!=a&&c!=b)
				for(d=1;d<=9;d++)
				{
					if(d!=a&&d!=b&&d!=c)
					for(e=1;e<=9;e++)
					{
						if(e!=a&&e!=b&&e!=c&&e!=d)
						for(f=1;f<=9;f++)
						{
							if(f!=a&&f!=b&&f!=c&&f!=d&&f!=e)
							for(g=1;g<=9;g++)
							{
								if(g!=a&&g!=b&&g!=c&&g!=d&&g!=e&&g!=f)
								for(h=1;h<=9;h++)
								{
									if(h!=a&&h!=b&&h!=c&&h!=d&&h!=e&&h!=f&&h!=g)
									for(i=1;i<=9;i++)
									{
										if(i!=a&&i!=b&&i!=c&&i!=d&&i!=e&&i!=f&&i!=g&&i!=h)
										{
											if((d*100+e*10+f)==2*(a*100+b*10+c)&&(g*100+h*10+i)==3*(a*100+b*10+c))
											printf("%d %d %d\n",a*100+b*10+c,d*100+e*10+f,g*100+h*10+i);
											break; 
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
	return 0;
 } 
