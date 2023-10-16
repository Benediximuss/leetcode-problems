#include <iostream>
#include <vector>

using namespace std;

void testRun(vector<int>(*fn)(int))
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	int cases[] = { 0, 1, 2, 3, 4, 10, 29};

	for (int i = 0; i < sizeof(cases) / sizeof(int); i++)
	{
		cout << "Case " << i + 1 << "\nInput = \"" << cases[i] << "\"\n";

		vector<int> output = fn(cases[i]);

		printf("Output = ");
		printList(output);
		printf("\n\n");
	}

}


/* Solution part */

int getElement(int row, int col, vector<vector<int>>& memo)
{
	int res = memo[row][col];

	if (res != -1)
		return res;

	if (row <= 1 || col == 0 || col == row)
		res = 1;
	else
		res = getElement(row - 1, col - 1, memo) + getElement(row - 1, col, memo);

	memo[row][col] = res;

	return res;
}

vector<int> getRow(int rowIndex)
{
	vector<int> targetRow(rowIndex + 1);

	vector<vector<int>> memo(rowIndex + 1);

	for (int i = 0; i < memo.size(); i++)
	{
		memo[i] = vector<int>(i + 1, -1);
	}

	for (int i = 0; i < targetRow.size(); i++)
	{
		targetRow[i] = getElement(rowIndex, i, memo);
	}

	return targetRow;
}

int main()
{
	testRun(getRow);

	return 0;
}