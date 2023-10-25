#include <iostream>
#include <vector>

using namespace std;

class Solution;

void testRun(int (Solution::* fn)(int, int), Solution* obj)
{
	vector<pair<int, int>> cases = { {1, 1} , {2, 1} , {2, 2} , {4, 5} };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nn = %d, k = %d\n", i + 1, cases[i].first, cases[i].second);

		int output = (obj->*fn)(cases[i].first, cases[i].second);

		printf("Output: %d\n\n", output);
	}

}

/* Solution part */

class Solution {
public:

	int kthGrammar(int n, int k)
	{
		string pathStack;

		int curr = pow(2, n - 1) + k - 1;
		while (curr > 1)
		{
			printf("Curr: %d\n", curr);
			pathStack += curr % 2 == 0 ? 'L' : 'R';
			curr /= 2;
		}

		printf("Path -> %s\n", pathStack.c_str());

		int ans = 0;
		while (!pathStack.empty())
		{
			ans = pathStack.back() == 'L' ? ans : 1 - ans;
			pathStack.pop_back();
		}

		return ans;
	}

};


int main()
{
	Solution solution;

	testRun(&Solution::kthGrammar, &solution);

	return 0;
}