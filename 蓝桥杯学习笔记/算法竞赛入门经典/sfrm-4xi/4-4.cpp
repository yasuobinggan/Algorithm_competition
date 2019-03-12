#include<stdio.h>
#include<string.h>
//rbgggr
//rggbgr
//tar 2,3,4,5
int c[4]={2,3,4,5} 
int a[3][4]={
	3,5,2,4,
	5,4,3,2,
	4,2,5,3
};
int b[4][4]={
	2,4,3,5,
	4,5,2,3,
	5,3,4,2,
	3,2,5,4
}; 
//不排序下对表进行匹配 
for(i=0;i<3;i++)//二维表行数 
{
	for(j=0;j<4;j++)//二维表列数 
	{
		for(k=0;k<4;k++)//一位表列数
		{
			if(a[i][j]==c[k]&&tar[j]==sou[k])
				break;
		 } 
		if(k==4)
			 break;
	}
	if(j==4)//找到匹配相 
		break;
}

bool judge2(char str[],char str1[])
{ 
	char tar[4],sou[4];	
	int i,j;
	//构建目标 
	for(int i=0;i<4;i++)
		tar[i]=str[i+1];
	for(int i=0;i<4;i++)
		sou[i]=str1[i+1];	
	if(sou[0]==tar[1] && sou[1]==tar[3] && sou[2]==tar[0] && sou[3]==tar[2])
		return true;
	if(sou[0]==tar[3] && sou[1]==tar[2] && sou[2]==tar[1] && sou[3]==tar[0])
		return true;
	if(sou[0]==tar[2] && sou[1]==tar[0] && sou[2]==tar[3] && sou[3]==tar[1])
		return true;
	return false; 
}
bool judge3(char str[],char str1[])
{
	char sou[4],tar[4];
	int i,j;
	for(int i=0;i<4;i++)
		tar[i]=str[i+1];
	for(int i=0;i<4;i++)
		sou[i]=str1[i+1];	
	if(sou[0]==tar[0]&&sou[1]==tar[2]&&sou[2]==tar[1]&&sou[3]==tar[3])
		return true;
	if(sou[0]==tar[2]&&sou[1]==tar[3]&&sou[2]==tar[0]&&sou[3]==tar[1])
		return true;
	if(sou[0]==tar[3]&&sou[1]==tar[1]&&sou[2]==tar[2]&&sou[3]==tar[0])
		return true;
	if(sou[0]==tar[1]&&sou[1]==tar[0]&&sou[2]==tar[3]&&sou[3]==tar[2])
		return true;
	return false;
}
bool judge1(char str[],char str1[])
{
	if(str[0]==str1[0] && str[5]==str1[5]) 
	{
		if(judge2(str,str1))
			return true;
		else
			return false;
	} 
	if(str[0]==str1[5] && str[5]==str1[0])
	{
		if(judge3(str,str1))
			return true;
		else
			return false;
	} 
	else
		return false;
}
int main()
{
	char str[6],str1[6];
	gets(str);gets(str1);
	if(judge1(str,str1))
		printf("YES\n");
	else
		printf("NO\n");	
	return 0;
 } 
