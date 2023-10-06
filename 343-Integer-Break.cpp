#include <iostream>

using namespace std;

void testRun(int(*fn)(int))
{
	int cases[] = { 2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	for (int i = 0; i < sizeof(cases) / sizeof(int); i++)
	{
		cout << "Case " << i + 1 << "\nInput = \"" << cases[i] << "\"\n";

		int output = fn(cases[i]);

		cout << "Output = " << output << endl << endl;
	}

}


/* Solution part */

int integerBreak(int n)
{
	if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else
	{
		int mod = n % 3;

		if (mod == 0)
		{
			return pow(3, n / 3);
		}
		else if (mod == 1)
		{
			return (pow(3, n / 3) * 4) / 3;
		}
		else
		{
			return pow(3, n / 3) * 2;
		}
	}	
}

int main()
{
	testRun(integerBreak);

	return 0;
}