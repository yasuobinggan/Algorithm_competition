/*******²âÊÔ×Ö·û´®º¯Êý********/
#include<string>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int len = 10;
void test_char_array()
{
	char *s;
	s = (char*)malloc(11 * sizeof(char));
	//s[10] = '\0';
	for (int i = 0; i<5; i++)
	{
		//scanf_s("%c", &s[i]);
		cin >> s[i];
	}
	/*
	for (int i = 0; i<5; i++)
	{
	//printf("%c ", s[i]);
	cout << s[i] << endl;
	}
	*/
	cout << s;
}
//×Ö·û×ª×Ö·û´®
void test_string()
{
	string s = "t";
	char c = 'H';
	s[0] = c;
	cout << s;
}
void getline_test()
{
	string ios[4];
	for (int i = 1; i <= 3; i++)
	{
		getline(cin, ios[i], '\n');

	}
	for (int i = 1; i <= 3; i++)
	{
		cout << ios[i] << endl;
	}
}
int main()
{
	//test_char_array();
	//test_string();
	getline_test();
	return 0;
}
