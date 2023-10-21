#include <iostream>
#include <vector>
#include <queue>

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

	struct testCase
	{
		vector<int> nums;
		int k;
	};

	vector<testCase> cases = { { {10,2,-10,5,20} , 2 } , { {-1,-2,-3} , 1 } , { {10,-2,-10,-5,20} , 2 } , { {-5266,4019,7336,-3681,-5767} , 2 } };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nNums = ", i + 1);
		printList(cases[i].nums);
		printf(" , k = %d\n", cases[i].k);

		int output = (obj->*fn)(cases[i].nums, cases[i].k);

		printf("Output: %d\n\n", output);
	}

}

/* Solution part */

class Solution
{
public:

	int constrainedSubsetSum(vector<int>& nums, int k)
	{
		vector<int> dp(nums.size());
		priority_queue<heapNode, vector<heapNode>, comperator> maxheap;

		maxheap.push(heapNode(nums[0], 0));

		int maxsum = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			while (maxheap.top().idx < i - k)
			{
				maxheap.pop();
			}

			int temp = nums[i] + max(0, maxheap.top().val);

			maxsum = max(maxsum, temp);

			maxheap.push(heapNode(temp, i));
		}

		return maxsum;
	}

	struct heapNode
	{
		int val;
		int idx;

		heapNode(int val, int idx)
			: val(val), idx(idx)
		{}
	};

	struct comperator
	{
		bool operator() (heapNode a, heapNode b)
		{
			return a.val < b.val;
		}
	};

};

int main()
{
	Solution solution;

	testRun(&Solution::constrainedSubsetSum, &solution);

	return 0;
}