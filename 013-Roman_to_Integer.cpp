#include <iostream>
#include <map>

using namespace std;

void testRun(int(*fn)(string))
{
	string cases[] = { "III", "IV", "LIII", "LIV", "MCMXCIV"};

	for (int i = 0; i < sizeof(cases) / sizeof(string); i++)
	{
		cout << "Case " << i + 1 << "\nInput = \"" << cases[i] << "\"\n";

		int output = fn(cases[i]);

		cout << "Output = " << output << endl << endl;
	}

}


/* Solution part */

void loadDict(map<char, int>& dict)
{
	dict['I'] = 1;
	dict['V'] = 5;
	dict['X'] = 10;
	dict['L'] = 50;
	dict['C'] = 100;
	dict['D'] = 500;
	dict['M'] = 1000;
}

int romanToInt(string str)
{
	map<char, int> dict;
	loadDict(dict);

	int result = 0;

	string temp;
	for (int i = 0; i < str.length(); i++)
	{

		if (temp.empty() || temp.back() == str[i])
		{
			temp += str[i];
		}
		else
		{
			if (temp.size() == 1 && dict[temp[0]] < dict[str[i]])
			{
				result += dict[str[i]] - dict[temp[0]];
				temp.clear();
			}
			else
			{
				result += dict[temp[0]] * temp.length();
				temp.clear();
				temp += str[i];
			}	
		}

	}

	if (!temp.empty())
	{
		result += dict[temp[0]] * temp.length();
	}

	return result;
}

int main()
{
	testRun(romanToInt);

	return 0;
}
