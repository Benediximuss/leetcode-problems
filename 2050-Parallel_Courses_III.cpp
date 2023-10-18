#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution;

void testRun(int (Solution::*fn)(int, vector<vector<int>>&, vector<int>&), Solution* obj)
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	auto print2dList = [](vector<vector<int>> list)
	{
		printf("[ ");
		for (int i = 0; i < list.size(); i++)
		{
			printf("[");
			for (int j = 0; j < list[i].size(); j++)
			{
				printf("%d%c", list[i][j], (j < list[i].size() - 1) ? ',' : '\0');
			}
			printf("]%c", (i < list.size() - 1) ? ',' : '\0');
		}
		printf(" ]");
	};

	struct testCase
	{
		int n;
		vector<vector<int>> relations;
		vector<int> time;
	};

	vector<testCase> cases = { { 3 , {{1,3},{2,3}} , {3,2,5} } , { 5 , {{1,5},{2,5},{3,5},{3,4},{4,5}} , {1,2,3,4,5} } , { 7 , {{1,7},{1,4},{1,3},{2,3},{4,3},{5,3},{7,3},{7,6}} , {6,5,1,8,2,9,4} } };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nn = %d, relations = ", i + 1, cases[i].n);
		print2dList(cases[i].relations);
		printf(" , time = ");
		printList(cases[i].time);
		printf("\n");

		int output = (obj->*fn)(cases[i].n, cases[i].relations, cases[i].time);

		printf("Output: %d\n\n", output);
	}

}

/* Solution part */

class Solution
{
public:

	int findEnd(int node, vector<int>& time)
	{
		if (memo[node - 1] != -1)
			return memo[node - 1];

		vector<int>& parents = graph[node];

		if (parents.empty())
			return time[node - 1];

		int res;

		int max = -1;

		for (int i = 0; i < parents.size(); i++)
		{
			int tempPath = findEnd(parents[i], time);

			if (tempPath > max)
				max = tempPath;
		}

		res = time[node - 1] + max;

		memo[node - 1] = res;

		return res;
	}

	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time)
	{
		for (int i = 1; i < n + 1; i++)
		{
			graph[i] = vector<int>();
		}

		for (int i = 0; i < relations.size(); i++)
		{
			graph[relations[i][0]].push_back(relations[i][1]);
		}

		memo = vector<int>(n, -1);

		int max = -1;

		for (int i = 1; i < n + 1; i++)
		{
			int tempPath = findEnd(i, time);

			if (tempPath > max)
				max = tempPath;
		}

		return max;
	}

private:

	unordered_map<int, vector<int>> graph;
	vector<int> memo;

};

int main()
{
	Solution solution;

	testRun(&Solution::minimumTime, &solution);

	return 0;
}