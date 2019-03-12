//#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int maxl = 1e5;
const int mod = 1e9 + 7;
char str[maxl];
int nump[maxl];
int numa[maxl];
int numt[maxl];
int main()
{
	memset(nump, 0, sizeof(nump));
	memset(numa, 0, sizeof(numa));
	memset(numt, 0, sizeof(numt));
	//gets_s(str);
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i<len; i++)
	{
		
		if (i>0)
			nump[i] = nump[i - 1];
		if (str[i] == 'P')
			(++nump[i]) %= mod;
		
	}

	//对a层的递推进行初始化
	int k = 0;
	for (k = 0; k<len; k++)
	{
		if (str[k] == 'A'&&nump[k]!=0)
		{
			numa[k] = nump[k];
			break;
		}

	}

	for (int i = k + 1; i<len; i++)
	{
		if (i>0)
			numa[i] = numa[i - 1];
		if (str[i] == 'A')
		{
			numa[i] += numa[i - 1];
			numa[i] %= mod;
		}
		
	}


	//对t层的递推进行初始化
	k = 0;
	for (k = 0; k<len; k++)
	{
		if (str[k] == 'T'&&numa[k]!=0)
		{
			numt[k] = numa[k];
			break;
		}
	}
	for (int i = k + 1; i<len; i++)
	{
		if (i>0)
			numt[i] = numt[i - 1];
		if (str[i] == 'T')
		{
			numt[i] += numt[i - 1];
			numt[i] %= mod;
		}
		
	}


	int sum = 0;
	for (int i = 0; i<len; i++)
	{
		if (str[i] == 'T')
			sum += numt[i];
	}
	//cout<<sum<<endl;
	printf("%d\n", sum);

	return 0;
}
//APPAPTV
