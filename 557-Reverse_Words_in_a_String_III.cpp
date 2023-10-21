#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution;

void testRun(string (Solution::*fn)(string), Solution* obj)
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	vector<string> cases = { "Let's take LeetCode contest" , "God Ding" };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\ns = \"%s\"\n", i + 1, cases[i].c_str());

		string output = (obj->*fn)(cases[i]);

		printf("Output: \"%s\"\n\n", output.c_str());
	}

}

/* Solution part */

class Solution
{
public:

	string reverseWords(string s)
	{
		stack<char> word;
		string res;

		word.push(' ');

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
				word.push(s[i]);
			else
			{
				unload(word, res);
				word.push(' ');
			}
		}

		unload(word, res);
		
		res.pop_back();

		return res;
	}

private:

	void unload(stack<char>& word, string& res)
	{
		while (!word.empty())
		{
			res += word.top();
			word.pop();
		}
	}

};

int main()
{
	Solution solution;

	testRun(&Solution::reverseWords, &solution);

	return 0;
}