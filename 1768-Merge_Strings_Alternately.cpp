#include <iostream>

using namespace std;

void testRun(string(*fn)(string, string))
{
    
	string cases[][2] = { { "abc", "pqr" }, { "ab", "pqrs" }, { "abcd", "pq" } };

	for (int i = 0; i < sizeof(cases)/(2*sizeof(string)); i++)
	{
		cout << "Case " << i + 1 << "\nWord1 = \"" << cases[i][0] << "\" Word2 = \"" << cases[i][1] << "\"\n";

		string output = fn(cases[i][0], cases[i][1]);

		cout << "Output = \"" << output << "\"" << endl << endl;
	}

}

string mergeAlternately(string word1, string word2) {

    string output;

    int len;
    string* shorter;
    string* longer;

    if (word1.length() >= word2.length())
    {
        len = word1.length();
        longer = &word1;
        shorter = &word2;
    }
    else
    {
        len = word2.length();
        longer = &word2;
        shorter = &word1;
    }

    int k = 0, i = 0;
    while (i < len)
    {
        if (i < shorter->length())
        {
            if (k % 2 == 0)
            {
                output += word1[i];
            }
            else
            {
                output += word2[i];
                i++;
            }
        }
        else
        {
            output += longer->at(i);
            i++;
        }

        k++;
    }

    return output;
}


int main()
{
    testRun(mergeAlternately);

    return 0;
}
