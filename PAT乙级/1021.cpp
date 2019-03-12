#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

void cut(int length)
{
	
}
void out(int length)
{
	
}
int main()
{
	char num[1005];
	int cnt[10];
	while(cin>>num)
	{
		//memset(cnt,0,sizeof(cnt));
		cnt[10]={0};
		int length=strlen(num);
		for(int i=0;i<length;i++)
		{
			cnt[num[i]-'0']++;
		}
		for(int i=0;i<length;i++)
		{
			if(cnt[i]!=0)
			cout<<i<<":"<<cnt[i]<<endl;
		}
		//cut(length);
		//out(length);
	}
	return 0;
}
//Âú·Ö³ÌÐò
#include <iostream>
using namespace std;

int main()
{
  char s[10000];
  while(cin>>s)
  {
    int d[10]={0},i;
    
    for(i=0;s[i];i++)
      d[s[i]-'0']++;
   
    for(i=0;i<10;i++)
      if(d[i])
      cout<<i<<":"<<d[i]<<endl;
  }
  return 0;
} 
