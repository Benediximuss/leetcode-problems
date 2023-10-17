#include <iostream>
#include <vector>

using namespace std;

class Solution;

void testRun(bool (Solution::*fn)(int, vector<int>&, vector<int>&), Solution* obj)
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
		int n;
		vector<int> leftChild;
		vector<int> rightChild;
	};

	vector<testCase> cases = { {4, {1,-1,3,-1}, {2,-1,-1,-1}} , {4, {1,-1,3,-1}, {2,3,-1,-1}} , {2, {1,0}, {-1,-1}} , {4, {3,-1,1,-1}, {-1,-1,0,-1}} , {4, {1,0,3,-1}, {-1,-1,-1,-1}} , {4, {1,-1,3,-1}, {2,-1,-1,-1} } };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nn = %d, leftChild = ", i + 1, cases[i].n);
		printList(cases[i].leftChild);
		printf(", rightChild = ");
		printList(cases[i].rightChild);
		printf("\n");

		bool output = (obj->*fn)(cases[i].n, cases[i].leftChild, cases[i].rightChild);

		printf("Output: %s\n\n", output ? "True" : "False");
	}

}

/* Solution part */

class Solution
{
public:

	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
	{
		parents = vector<int>(n, -1);

		for (int i = 0; i < leftChild.size(); i++)
		{
			if (leftChild[i] != -1)
			{
				if (parents[leftChild[i]] == -1)
				{
					parents[leftChild[i]] = i;
				}
				else
					return false;
			}
		}

		for (int i = 0; i < rightChild.size(); i++)
		{
			if (rightChild[i] != -1)
			{
				if (parents[rightChild[i]] == -1)
				{
					parents[rightChild[i]] = i;
				}
				else
					return false;
			}
		}

		root = -1;
		for (int i = 0; i < parents.size(); i++)
		{
			if (parents[i] == -1)
			{
				if (root == -1)
					root = i;
				else
					return false;
			}
		}

		if (root == -1)
			return false;

		memo = vector<int>(n, -1);

		for (int i = 0; i < n; i++)
		{
			if (memo[i] == -1)
			{
				int callcount = 0;
				int parentRoot = findRoot(i, callcount);

				if (parentRoot != root)
					return false;
				else
					memo[i] = parentRoot;
			}
		}

		return true;
	}

private:

	vector<int> parents;
	int root;
	vector<int> memo;

	int findRoot(int node, int& callcount)
	{
		if (callcount == parents.size())
			return -1;

		callcount++;

		if (node == root)
			return root;

		return findRoot(parents[node], callcount);
	}

};

int main()
{
	Solution solution;

	testRun(&Solution::validateBinaryTreeNodes, &solution);

	return 0;
}