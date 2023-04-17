#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testRun(vector<bool>(*fn)(vector<int>&, int))
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	struct testCase
	{
		vector<int> candies;
		int extraCandies;
	};

	vector<testCase> cases = { {vector<int> {2,3,5,1,3}, 3}, {vector<int> {4,2,1,1,2}, 1}, {vector<int> {12,1,12}, 10} };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nCandies = ", i + 1);
		printList(cases[i].candies);
		printf(", ExtraCandies = %d\n", cases[i].extraCandies);

		vector<bool> output = fn(cases[i].candies, cases[i].extraCandies);

		printf("Output = ");

		printf("[");
		for (int i = 0; i < output.size(); i++)
		{
			printf("%c%c", output[i] ? 'T': 'F', (i < output.size() - 1) ? ',' : '\0');
		}
		printf("]\n");


		printf("\n");
	}

}


/* Solution part */

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
	vector<bool> output(candies.size());

	int max = 0;

	for (int i = 0; i < candies.size(); i++)
	{
		if (candies[i] > max)
		{
			max = candies[i];
		}
	}

	for (int i = 0; i < candies.size(); i++)
	{
		output[i] = candies[i] + extraCandies >= max ? true : false;
	}

	return output;
}

int main()
{
	testRun(kidsWithCandies);

	return 0;
}