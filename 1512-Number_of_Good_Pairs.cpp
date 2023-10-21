#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution;

void testRun(int (Solution::*fn)(vector<int>&), Solution* obj)
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	vector<vector<int>> cases = { {1,2,3,1,1,3} , {1,1,1,1} , {1,2,3} };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nnums = ", i + 1);
		printList(cases[i]);
		printf("\n");

		int output = (obj->*fn)(cases[i]);

		printf("Output: %d\n\n", output);
	}

}

/* Solution part */

class Solution {
public:
	int numIdenticalPairs(vector<int>& nums)
	{
		int res = 0;

		sort(nums.begin(), nums.end());

		int dup = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == nums[i - 1])
			{
				dup++;
			}
			else
			{
				res += (dup * (dup + 1)) / 2;
				dup = 0;
			}
		}

		res += (dup * (dup + 1)) / 2;

		return res;
	}
};

int main()
{
	Solution solution;

	testRun(&Solution::numIdenticalPairs, &solution);

	return 0;
}