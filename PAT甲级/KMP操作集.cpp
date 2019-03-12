const int maxn=1e5;
int next[maxn];
//递推计算next数组
void next(char s[],int len)
{
	next[0]=-1;
	int j=-1;//查找扩展位置的指针

	//从前往后遍历数组
	for(int i=1;j<len;i++)
	{
		//匹配不成功向前查找
		//两种条件满足一个就停止查找
		while(j!=-1&&s[j+1]!=s[i])
		{
			//向之前的方向查找
			j=next[j];
		}
		//匹配成功指针移动
		if(s[j+1]==s[i])
		{
			j++;
		}
		//记录next数组
		next[i]=j;
	 }
 }
 //普通KMP匹配
 bool KMP(char text[],char pattern[])
 {
 	int n=strlen(text),m=strlen(pattern);
 	//计算pattern的next数组
	 getNext(pattern,m);
 	//初始化j
 	int j=-1;
 	for(int i=0;i<n;i++)
 	{
 		while(j!=-1&&pattern[j+1]!=text[i])
 		{
 			j=next[j];
		 }
		if(pattern[j+1]==text[i])
		{
			j++;
		}
		//匹配到最后一位成功
		if(j==m-1)
		{
			return true;
		}
	 }
	 return false;
}
//记录出现次数的KMP匹配
int KMP(char text[],char pattern[])
{
    int n=strlen(text),m=strlen(pattern);
    getNext(pattern,m);

    int ans=0,j=-1;
    for(int i=0;i<n;i++)
    {
        while(j!=-1&&pattern[j+1]!=text[i])
        {
            j=next[j];
        }
        if(pattern[j+1]==text[i])
        {
            j++;
        }
        //pattern匹配成功
        if(j==m-1)
        {
            ans++;
            //j回退到next[j]继续匹配
            j=next[j];
        }
    }
    return ans;
}
