#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* Solution part */

class Solution {
public:
	const int mod = 1e9 + 7;

	int count(int vowel, int n, vector<vector<int>>& dp)
	{
		if (n == 1)
			return 1;

		if (dp[vowel][n - 1] != -1)
			return dp[vowel][n - 1];

		unsigned int ans = 0;

		if (vowel == 0)
			ans = count(1, n - 1, dp) % mod;
		else if (vowel == 1)
		{
			ans = count(0, n - 1, dp) % mod;
			ans = (ans + count(2, n - 1, dp)) % mod;
		}
		else if (vowel == 3)
		{
			ans = count(2, n - 1, dp) % mod;
			ans = (ans + count(4, n - 1, dp)) % mod;
		}
		else if (vowel == 4)
			ans = count(0, n - 1, dp) % mod;
		else
		{
			ans = count(0, n - 1, dp) % mod;
			ans = (ans + count(1, n - 1, dp)) % mod;
			ans = (ans + count(3, n - 1, dp)) % mod;
			ans = (ans + count(4, n - 1, dp)) % mod;
		}

		dp[vowel][n - 1] = ans;

		return ans;
	}

	int countVowelPermutation(int n)
	{
		vector<vector<int>> dp(5, vector<int>(n, -1));

		int ans = 0;

		for (int i = 0; i < 5; i++)
		{
			ans = (ans + count(i, n, dp)) % mod;
		}

		return ans;
	}
};


/* Testing Function */

void testRun(int (Solution::*fn)(int))
{
	vector<int> cases = { 1, 2, 5, 144 };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nn = %d\n", i + 1, cases[i]);

		int output = (Solution().*fn)(cases[i]);

		printf("Output: %d\n\n", output); 
	}

}


int main()
{
	testRun(&Solution::countVowelPermutation);

    return 0;
}