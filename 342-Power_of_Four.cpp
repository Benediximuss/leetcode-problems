#include <iostream>
#include <vector>

using namespace std;

class Solution;

void testRun(bool (Solution::*fn)(int), Solution* obj)
{
	vector<int> cases = { 16 , 5 , 1 , -65 };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nn = %d\n", i + 1, cases[i]);

		bool output = (obj->*fn)(cases[i]);

		printf("Output: %s\n\n", output ? "true" : "false");
	}

}

/* Solution part */

class Solution {
public:
	bool isPowerOfFour(int n)
	{
		// Negative OR not power of 2
		if (n <= 0 || (n & (n - 1)) != 0)
			return false;

		int pow_two = 0;
		while (n > 1)
		{
			pow_two++;
			n >>= 1;
		}

		return pow_two % 2 == 0;
	}
};

int main()
{
	Solution solution;

	testRun(&Solution::isPowerOfFour, &solution);

	return 0;
}