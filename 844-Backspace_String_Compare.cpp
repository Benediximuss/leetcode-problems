#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution;

void testRun(bool (Solution::*fn)(string, string), Solution* obj)
{
	struct testCase
	{
		string s;
		string t;
	};

	vector<testCase> cases = { { "ab#c" , "ad#c" } , { "ab##" , "c#d#" } , { "a#c" , "b" } };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\ns = \"%s\", t = \"%s\"\n", i + 1, cases[i].s.c_str(), cases[i].t.c_str());

		bool output = (obj->*fn)(cases[i].s, cases[i].t);

		printf("Output: %s\n\n", output ? "true" : "false");
	}

}

/* Solution part */

class Solution
{
public:

	bool backspaceCompare(string s, string t)
	{
		stack<char> word1;
		stack<char> word2;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != '#')
				word1.push(s[i]);
			else if (!word1.empty())
				word1.pop();
		}

		for (int i = 0; i < t.length(); i++)
		{
			if (t[i] != '#')
				word2.push(t[i]);
			else if (!word2.empty())
				word2.pop();
		}


		if (word1.size() != word2.size())
			return false;


		while (!word1.empty())
		{
			if (word1.top() != word2.top())
				return false;

			word1.pop();
			word2.pop();
		}

		return true;
	}

};

int main()
{
	Solution solution;

	testRun(&Solution::backspaceCompare, &solution);

	return 0;
}