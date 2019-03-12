#include<stdio.h>
#include<math.h>
typedef struct{
	int distance;
	int direction;
	int gan;
}Mayi;
Mayi map[50];
void create_map(Mayi map[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&map[i].distance);
		if(map[i].distance>0)
			map[i].direction=1;
		else
			map[i].direction=-1;
		map[i].distance=abs(map[i].distance);
		if(i)
			map[i].gan=0;
		else 
			map[i].gan=1;
	}
}
int pachu(Mayi map[],int n)
{
	int i=0;
	while(true)
	{
		if(map[i].distance==0||map[i].distance==99)
			i++;
		else
			return 0;
	}
	return 1;
}
void ganmao(Mayi map[],int n)
{
	int i;
	while(true)
	{
		
		for(i=0;i<n;i++)
		{
			if(map[i].direction>0)
				++map[i].distance;
			else
				--map[i].distance;
		}
		for(i=0;i<n-1;i=i+2)
		{
			if(map[i].distance==map[i+1].distance)
			{
				map[i].direction=-map[i].direction;
				map[i+1].direction=-map[i+1].direction;
				if(map[i].gan==1||map[i+1].gan==1)
					map[i].gan=map[i].gan=1;
			}
		}
		if(pachu(map,n))
			break;
	}
	
}
int print_map(Mayi map[],int n)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(map[i].gan==1)
			count++;
	}
		printf("%d:%d:%d\t",map[i].distance,map[i].direction,map[i].gan);
	return count;
}
int main()
{
	int n;
	printf("输入蚂蚁个数:\n");
	scanf("%d",&n);
	printf("输入蚂蚁:\n");
	create_map(map,n);
	ganmao(map,n);
	printf("%d",print_map);
	return 0;
}
