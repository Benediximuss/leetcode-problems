#include <iostream>
#include <vector>

using namespace std;

void testRun(int(*fn)(vector<int>&))
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	vector<vector<int>> cases = { {2,2,1} , {4,1,2,1,2} , {1} };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nNums = ", i + 1);
		printList(cases[i]);
		printf("\n");

		int output = fn(cases[i]);

		cout << "Output = " << output << endl << endl;
	}

}


/* Solution part */

int singleNumber(vector<int>& nums) {
	int result = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		result ^= nums[i];
	}

	return result;
}

int main()
{
	testRun(singleNumber);

	return 0;
}