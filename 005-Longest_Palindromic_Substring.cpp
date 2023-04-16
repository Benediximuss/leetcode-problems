#include <iostream>

using namespace std;

void testRun(string(*fn)(string))
{
	string cases[] = { "a", "babad", "cbbd", "babadcbbdbbcdabdaba", "aacabdkaashrcabdkacaaaacabdakacaaaacaacabdkacadkacaadkacaaacabdkacaaaacabdkacaaaacabdkacaaaacabdkacaaaacabdkacaaa"};

	for (int i = 0; i < sizeof(cases) / sizeof(string); i++)
	{
		cout << "Case " << i + 1 << "\nInput = \"" << cases[i] << "\"\n";

		string output = fn(cases[i]);

		cout << "Output = \"" << output << "\"" << endl << endl;
	}

}


/* Solution part */

string longestPalindrome(string str)
{
    int max = 0;

    int maxL = -1;
    int maxK = -1;

    for (int i = 0; i < str.length() && max < (i < str.length() / 2 ? (i + 1) * 2 : (str.length() - 1 - i) * 2 + 1); i++)
    {
        int l = i;
        int r = i;

        bool isValidOdd = true;
        bool isValidEven = true;

        int k = 0;
        while ((isValidOdd || isValidEven) && (l >= 0 && r < str.length()))
        {
            if (str[l] == str[r])
            {
                if ((k % 2 == 0 && isValidOdd) || (k % 2 != 0 && isValidEven))
                {
                    if (k + 1 > max)
                    {
                        maxL = l;
                        maxK = k;

                        max = k + 1;
                    }
                }
            }
            else
            {
                if (k % 2 == 0)
                {
                    isValidOdd = false;
                }
                else
                {
                    isValidEven = false;
                }
            }

            if (k % 2 == 0)
            {
                r++;
            }
            else
            {
                l--;
            }

            k++;
        }

    }

    return str.substr(maxL, maxK + 1);
}

int main()
{
    testRun(longestPalindrome);

	return 0;
}
