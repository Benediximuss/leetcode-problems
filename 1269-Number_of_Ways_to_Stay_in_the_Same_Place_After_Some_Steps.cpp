#include <iostream>
#include <vector>

using namespace std;

void testRun(int(*fn)(int, int))
{
	struct testCase
	{
		int steps;
		int arrLen;
	};

	vector<testCase> cases = { {3, 2} , {2, 4}, {4, 2}, {4, 3}, {27, 7} };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nSteps = %d, arrLen = %d\n", i + 1, cases[i].steps, cases[i].arrLen);

		int output = fn(cases[i].steps, cases[i].arrLen);

		printf("Output = %d\n\n", output);
	}

}


/* Solution part */

int waystozero(int pos, int steps, int arrLen, vector<vector<int>>& memo, int mod)
{
	if (memo[pos][steps] != -1)
		return memo[pos][steps];
	else
	{
		int res;

		if (steps == 0)
			res = pos == 0 ? 1 : 0;
		else
		{
			// stay
			res = waystozero(pos, steps - 1, arrLen, memo, mod) % mod;

			// left
			if (pos > 0)
				res = (res + waystozero(pos - 1, steps - 1, arrLen, memo, mod)) % mod;

			// right
			if (pos < arrLen - 1)
				res = (res + waystozero(pos + 1, steps - 1, arrLen, memo, mod)) % mod;
		}

		memo[pos][steps] = res;

		return res;
	}
}

int numWays(int steps, int arrLen)
{
	arrLen = min(arrLen, steps + 1);

	vector<vector<int>> memo(arrLen, vector<int>(steps + 1, -1));

	int mod = 1e9 + 7;

	return waystozero(0, steps, arrLen, memo, mod);
}


int main()
{
	testRun(numWays);

	return 0;
}