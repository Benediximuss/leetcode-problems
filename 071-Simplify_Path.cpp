#include <iostream>
#include <string>

using namespace std;

void testRun(string (*fn)(string))
{

	string cases[] = { "/home/", "/../", "/home/documents/../../../.././pictures", "/home//foo/", "/home/user/Documents/../Pictures", "/home/user/./Downloads/../Pictures/././", "/home/user/Documents/../../../usr/../local/bin/../.."};

	for (int i = 0; i < sizeof(cases)/sizeof(string); i++)
	{
		cout << "Case " << i + 1 << "\nInput = " << cases[i] << endl;

		string output = fn(cases[i]);

		cout << "Output = " << output << endl << endl;
	}

}


/* Solution part */
void popPath(string& path)
{
	while (path.back() != '/')
	{
		path.pop_back();
	}

	if (path.size() > 1)
	{
		path.pop_back();
	}
}


string simplifyPath(string path)
{
	string output = "/";
	string token = "";

	for (int i = 1; i < path.size() + 1; i++)
	{
		if (i == path.size() || path[i] == '/')
		{
			if (token.length() == 1 && token[0] == '.')
			{
				token.clear();
			}
			else if (token.length() == 2 && token[0] == '.' && token[1] == '.')
			{
				popPath(output);
				token.clear();
			}
			else if (token.length() > 0)
			{
				output += output.back() == '/' ? token : '/' + token;
				token.clear();
			}
		}
		else
		{
			token += path[i];
		}

	}

	return output;
}

int main()
{

	testRun(simplifyPath);

	return 0;
}
