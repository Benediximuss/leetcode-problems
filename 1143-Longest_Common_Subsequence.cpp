#include <iostream>
#include <vector>

using namespace std;

void testRun(int(*fn)(string, string))
{

	vector<vector<string>> cases = { { "abcde", "ace" }, { "abc", "abc" }, { "abc", "def" } };

	for (int i = 0; i < cases.size(); i++)
	{
		cout << "Case " << i + 1 << "\nText1 = \"" << cases[i][0] << "\" Text 2 = \"" << cases[i][1] << "\"\n";

		int output = fn(cases[i][0], cases[i][1]);

		cout << "Output = " << output << endl << endl;
	}

}

int fn(string text1, string text2)
{
	vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));

	for (int j = 1; j < dp[0].size(); j++)
	{
		for (int i = 1; i < dp.size(); i++)
		{
			dp[i][j] = text1[i-1] == text2[j-1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[text1.length()][text2.length()];
}

int main()
{
	testRun(fn);

	return 0;
}