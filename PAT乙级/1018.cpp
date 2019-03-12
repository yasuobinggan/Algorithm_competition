#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
#define mn 100000+5
//B£¬C£¬J 
//B>C,C>J,J>B
char JIA[mn],YI[mn];
int N;
int JIAr[3],YIr[3];//jiayiµÄÊ¤Æ½¸º 
int JIAz[3],YIz[3];
 
int main()
{
	memset(JIAr,0,sizeof(JIAr));
	memset(YIr,0,sizeof(YIr));
	memset(JIAz,0,sizeof(JIAz));
	memset(YIz,0,sizeof(YIz));
	
	cin>>N;
	int i;
	
	for(i=0;i<N;i++)
	{
		cin>>JIA[i];cin>>YI[i];
		switch(JIA[i])
		{
			case 'B':
				switch(YI[i])
				{
					case 'B':JIAr[1]++;YIr[1]++;break;
					case 'C':JIAr[0]++;YIr[2]++;YIz[1]++;break;
					case 'J':JIAr[2]++;YIr[0]++;JIAz[0]++;break; 
				}
				break;
			case 'C':
				switch(YI[i])
				{
					case 'B':JIAr[2]++;YIr[0]++;JIAz[0]++;break;
					case 'C':JIAr[1]++;YIr[1]++;break;
					case 'J':JIAr[0]++;YIr[2]++;YIz[2]++;break;
				}
				break;
			case 'J':
				switch(YI[i])
				{
					case 'B':JIAr[0]++;YIr[2]++;JIAz[2]++;break;
					case 'C':JIAr[2]++;YIr[0]++;YIz[1]++;break;
					case 'J':JIAr[1]++;YIr[1]++;break;
				}
				break;
		 } 
	}
	for(int i=0;i<3;i++)
		cout<<JIAr[i]<<" ";
	cout<<endl;
	for(int i=0;i<3;i++)
		cout<<YIr[i]<<" ";
	cout<<endl;
	int m=0;
	int m1=-1;
	for(int i=2;i>=0;i--)
		if(JIAz[i]>=m)
		{
			m=JIAz[i];
			m1=i;
		}
	switch(m1)
	{
		case 0:cout<<'B'<<" ";break;
		case 1:cout<<'C'<<" ";break;
		case 2:cout<<'J'<<" ";break;
	}
	m=0;
	m1=-1;
	for(int i=2;i>=0;i--)
		if(YIz[i]>=m)
		{
			m=JIAz[i];
			m1=i;
		}	
	switch(m1)
	{
		case 0:cout<<'B';break;
		case 1:cout<<'C';break;
		case 2:cout<<'J';break;
	}
	//cout<<endl;
	return 0;
}
