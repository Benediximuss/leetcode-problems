#include <iostream>
#include <vector>

using namespace std;

void testRun(int(*fn)(vector<int>&, int))
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	struct testCase {
		vector<int> nums;
		int target;
	};

	vector<testCase> cases = { { {-1,0,3,5,9,12} , 9 } , { {-1,0,3,5,9,12} , 2 } };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nNums = ", i + 1);
		printList(cases[i].nums);
		printf(", target = %d\n", cases[i].target);

		int output = fn(cases[i].nums, cases[i].target);

		cout << "Output = " << output << endl << endl;
	}

}


/* Solution part */

int search(vector<int>& nums, int target)
{
	int begin = 0;
	int end = nums.size() - 1;

	while (begin <= end)
	{
		int mid = begin + (end - begin) / 2;

		if (nums[mid] == target)
		{
			return mid;
		}

		if (nums[mid] < target)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return -1;
}

int main()
{
	testRun(search);

	return 0;
}