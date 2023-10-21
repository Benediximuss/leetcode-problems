#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution;

void testRun(int (Solution::*fn)(vector<int>&, vector<int>&), Solution* obj)
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	vector<pair<vector<int>, vector<int>>> cases = { { {2,1,-2,5} , {3,0,-6} } , { {3,-2} , {2,-6,7} } , { {-1,-1} , {1,1} } };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nnums1 = ", i + 1);
		printList(cases[i].first);
		printf(", nums2 = ");
		printList(cases[i].second);
		printf("\n");

		int output = (obj->*fn)(cases[i].first, cases[i].second);

		printf("Output: %d\n\n", output);
	}

}

/* Solution part */

class Solution {
public:

	int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
	{
		vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));

		dp[0][0] = nums1[0] * nums2[0];

		for (int i = 1; i < dp.size(); i++)
		{
			dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
		}

		for (int j = 1; j < dp[0].size(); j++)
		{
			dp[0][j] = max(dp[0][j - 1], nums1[0] * nums2[j]);
		}

		for (int j = 1; j < dp[0].size(); j++)
		{
			for (int i = 1; i < dp.size(); i++)
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				dp[i][j] = max(dp[i][j], max(0, dp[i - 1][j - 1]) + nums1[i] * nums2[j]);
			}
		}

		return dp[nums1.size() - 1][nums2.size() - 1];
	}

};

int main()
{
	Solution solution;

	testRun(&Solution::maxDotProduct, &solution);

	return 0;
}