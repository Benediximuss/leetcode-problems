#include <iostream>
#include <vector>

using namespace std;

class Solution;

void testRun(int (Solution::*fn)(vector<int>&, int), Solution* obj)
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	vector<pair<vector<int>, int>> cases = { { {1,4,3,7,4,5} , 3 } , { {5,5,4,5,4,1,1,1} , 0 } };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nnums = ", i + 1);
		printList(cases[i].first);
		printf(", k = %d\n", cases[i].second);

		int output = (obj->*fn)(cases[i].first, cases[i].second);

		printf("Output: %d\n\n", output);
	}

}

/* Solution part */

class Solution {
public:

	int maximumScore(vector<int>& nums, int k)
	{
		vector<int> rightMins(nums.size() - k);
		rightMins[0] = nums[k];

		int maxScore = nums[k];

		for (int i = 1; i < rightMins.size(); i++)
		{
			rightMins[i] = min(rightMins[i - 1], nums[i + k]);
			maxScore = max(maxScore, rightMins[i] * (i + 1));
		}

		if (k == 0)
			return maxScore;

		vector<int> leftMins(k);
		leftMins[k - 1] = nums[k - 1];

		for (int i = k - 2; i > -1; i--)
		{
			leftMins[i] = min(leftMins[i + 1], nums[i]);
		}

		for (int i = 0; i < rightMins.size(); i++)
		{
			int leftEnd = findIndex(leftMins, rightMins[i], 0, leftMins.size() - 1);
			
			if (leftEnd < leftMins.size())
			{
				maxScore = max(maxScore, rightMins[i] * (i + 1 + k - leftEnd));
			}
		}

		reverse(rightMins.begin(), rightMins.end());

		for (int i = 0; i < leftMins.size(); i++)
		{
			int rightEnd = findIndex(rightMins, leftMins[i], 0, rightMins.size() - 1);

			if (rightEnd < rightMins.size())
				maxScore = max(maxScore, leftMins[i] * ((int)rightMins.size() - rightEnd + k - i));

		}

		return maxScore;
	}

private:

	int findIndex(vector<int>& nums, int target, int begin, int end)
	{
		int len = end - begin + 1;
		int mididx = (len - 1) / 2 + begin;

		if (target < nums[mididx])
		{
			if (mididx == 0)
			{
				return mididx;
			}
			else
			{
				if (target > nums[mididx - 1])
				{
					return mididx;
				}
				else
				{
					return findIndex(nums, target, begin, mididx - 1);
				}
			}
		}
		else if (target > nums[mididx])
		{
			if (mididx == nums.size() - 1)
			{
				return mididx + 1;
			}
			else
			{
				if (target < nums[mididx + 1])
				{
					return mididx + 1;
				}
				else
				{
					return findIndex(nums, target, mididx + 1, end);
				}
			}
		}
		else
		{
			if (mididx - 1 >= 0)
			{
				if (nums[mididx - 1] < target)
				{
					return mididx;
				}
				else
				{
					return findIndex(nums, target, begin, mididx - 1);
				}
			}
			else
			{
				return mididx;
			}
		}

	}

};

int main()
{
	Solution solution;

	testRun(&Solution::maximumScore, &solution);

	return 0;
}