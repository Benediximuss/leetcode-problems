#include <iostream>

using namespace std;

void testRun(int(*fn)(string))
{
	string cases[] = { "bbbab", "cbbd", "abbdfgcutfbb"};

	for (int i = 0; i < sizeof(cases)/sizeof(string); i++)
	{
		cout << "Case " << i + 1 << "\nText1 = \"" << cases[i] << "\"\n";

		int output = fn(cases[i]);

		cout << "Output = " << output << endl << endl;
	}

}


/* Solution part */

int longestPalindromeSubseq(string s)
{
	int size = s.length() + 1;

	int** dp = new int*[size];

	for (int i = 0; i < size; i++)
	{
		dp[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			dp[i][j] = 0;
		}
	}

	for (int j = 1; j < size; j++)
	{
		for (int i = 1; i < size; i++)
		{
			dp[i][j] = s[i - 1] == s[s.length() - j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int output = dp[s.length()][s.length()];

	for (int i = 0; i < size; i++)
	{
		delete[] dp[i];
	}

	delete[] dp;

	return output;
}

int main()
{
	testRun(longestPalindromeSubseq);

	return 0;
}