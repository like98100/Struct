#include <iostream>
#include <string>
using namespace std;

bool checkParentheses(string value)
{
	int ptheses[3][2] = { 0 };

	for (int i = 0; i < value.size(); i++)
	{
		if (value.at(i) == '(') ptheses[0][0]++;
		else if (value.at(i) == ')') ptheses[0][1]++;

		if (value.at(i) == '{')
		{
			if (ptheses[0][0] > ptheses[1][0]) return false;
			ptheses[1][0]++;
		}
		else if (value.at(i) == '}')
		{
			if (ptheses[0][1] < ptheses[1][1]) return false;
			ptheses[1][1]++;
		}

		if (value.at(i) == '[')
		{
			if (ptheses[0][0] > ptheses[2][0] || ptheses[1][0] > ptheses[2][0]) return false;
			ptheses[2][0]++;
		}
		else if (value.at(i) == ']')
		{
			if (ptheses[0][1] < ptheses[2][1] || ptheses[1][1] < ptheses[2][1]) return false;
			ptheses[2][1]++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (ptheses[i][0] != ptheses[i][1]) return false;
	}
	return true;
}

int main()
{
	string math[] = {"()", ")(", "{3+(2*5)}", "{}", "(3*4+(6)", "({2+5})"};

	for (int i = 0; i < 6; i++)
		if (checkParentheses(math[i])) cout << "Yes" << endl;
		else cout << "No" << endl;

	return 0;
}