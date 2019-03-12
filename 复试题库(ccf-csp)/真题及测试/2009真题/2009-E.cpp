//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<char> s;
bool judge(string input)
{
	for (int i = 0; i<input.size(); i++)
	{
		if (input[i] == '(' || input[i] == '[' || input[i] == '{' || input[i] == ')' || input[i] == ']' || input[i] == '}')
		{
			if (input[i] == '(' || input[i] == '[' || input[i] == '{')
			{
				s.push_back(input[i]);
			}
			else
			{
				if (s.empty())
					return false;
				if (!s.empty() && input[i] == ')'&&s.back() == '(')
				{
					s.pop_back();
				}
				if (!s.empty() && input[i] == ']'&&s.back() == '[')
				{

					s.pop_back();
				}
				if (!s.empty() && input[i] == '}'&&s.back() == '{')
				{

					s.pop_back();
				}
			}
		}


	}

	if (s.empty())
		return true;
	else
		return false;

}
int main()
{
	int n;
	cin >> n;
	string input;
	//char input;
	for (int i = 1; i <= n; i++)
	{
		s.clear();
		cin >> input;
		if (judge(input))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
/*
4
[(d+f)*{}]
[(2+3)]
()}
[4(6]7)9
*/
