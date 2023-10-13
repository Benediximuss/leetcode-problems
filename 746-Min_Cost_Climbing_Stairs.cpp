#include <iostream>
#include <vector>

using namespace std;

void testRun(int(*fn)(vector<int>&))
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	vector<vector<int>> cases = { {10,15,20} , {1,100,1,1,1,100,1,1,100,1}, {3,5,4,2,5} };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nCosts = ", i + 1);
		printList(cases[i]);
		printf("\n");

		int output = fn(cases[i]);

		printf("Output = %d\n\n", output);
	}

}


/* Solution part */


// Recursive Approach
int minCost(vector<int>& cost, int idx)
{
	if (idx <= 1)
		return 0;

	return min(minCost(cost, idx - 1) + cost[idx - 1], minCost(cost, idx - 2) + cost[idx - 2]);
}

int minCostClimbingStairsNaive(vector<int>& cost)
{
	return minCost(cost, cost.size());
}


// Dynamic Programming Apporach
int minCostClimbingStairsDP(vector<int>& cost)
{
	vector<int> dpTable(cost.size() + 1);

	dpTable[0] = 0;
	dpTable[1] = 0;

	for (int i = 2; i < cost.size() + 1; i++)
	{
		dpTable[i] = min(dpTable[i - 1] + cost[i - 1], dpTable[i - 2] + cost[i - 2]);
	}

	return dpTable[cost.size()];
}

int main()
{
	testRun(minCostClimbingStairsDP);

	return 0;
}