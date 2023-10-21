#include <iostream>
#include <vector>

using namespace std;

class Solution;

void testRun(bool (Solution::*fn)(string), Solution* obj)
{
	vector<string> cases = { "AAABABB" , "AA" , "ABBBBBBBAAA" };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\ncolors = %s\n", i + 1, cases[i].c_str());

		bool output = (obj->*fn)(cases[i]);

		printf("Output: %s\n\n", output ? "true" : "false");
	}

}

/* Solution part */

class Solution {
public:

	bool winnerOfGame(string colors)
	{
		int curr = colors[0] == 'A' ? 0 : 1;

		int turns[2] = {};

		int count = 1;

		for (int i = 1; i < colors.length(); i++)
		{
			if (colors[i] == colors[i-1])
				count++;
			else
			{
				turns[curr] += max(0, count - 2);
				curr = 1 - curr;
				count = 1;
			}
		}

		turns[curr] += max(0, count - 2);

		return turns[0] > turns[1];
	}
};

int main()
{
	Solution solution;

	testRun(&Solution::winnerOfGame, &solution);

	return 0;
}