#include <iostream>
#include <string>

using namespace std;

void testRun(bool(*fn)(int))
{
	int cases[] = { 121, -121, 10, 245, 122565221 };

	for (int i = 0; i < sizeof(cases) / sizeof(int); i++)
	{
		cout << "Case " << i + 1 << "\nInput = " << cases[i] << "\n";

		bool output = fn(cases[i]);

		cout << "Output = " << (output ? "True" : "False") << endl << endl;
	}

}

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    else
    {
        string xStr = to_string(x);

        int i = (xStr.length()-1) / 2;
        int j = xStr.length() / 2;
        bool res = true;
        
        while (i >= 0 && j < xStr.length() && res)
        {
            if (xStr[i] != xStr[j])
            {
                res = false;
            }
            else
            {
                i--;
                j++;
            }
        }

        return res;
    }

}

int main()
{
    testRun(isPalindrome);

    return 0;
}