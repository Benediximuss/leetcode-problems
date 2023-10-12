#include <iostream>
#include <vector>

using namespace std;

class MountainArray
{
public:
	MountainArray(vector<int> input)
	{
		arr = input;
	}

	int get(int index)
	{
		return arr[index];
	}
	int length()
	{
		return arr.size();
	}

private:
	vector<int> arr;

};


void testRun(int(*fn)(int, MountainArray&))
{
	auto printList = [](MountainArray list) {
		printf("[");
		for (int i = 0; i < list.length(); i++)
		{
			printf("%d%c", list.get(i), (i < list.length() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	struct testCase
	{
		MountainArray marr;
		int target;
	};

	vector<testCase> cases = { {MountainArray(vector<int> {1,2,3,4,5,3,1}) , 3} , {MountainArray(vector<int> {0,1,2,4,2,1}) , 3}, {MountainArray(vector<int> {1,5,2}) , 2}};


	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\nArray = ", i + 1);
		printList(cases[i].marr);
		printf(", target = %d\n", cases[i].target);

		int output = fn(cases[i].target, cases[i].marr);

		printf("Output = %d\n\n", output);
	}

}



/* Solution part */

int findPeak(MountainArray& mountainArr, int begin, int end)
{
	int len = end - begin + 1;
	int mididx = (len - 1) / 2 + begin;

	if (begin == 0)
	{
		return findPeak(mountainArr, begin + 1, end);
	}
	else if (end == mountainArr.length() - 1)
	{
		return findPeak(mountainArr, begin, end - 1);
	}
	else
	{
		if (begin < end)
		{
			int midVal = mountainArr.get(mididx);
			int midleftval = mountainArr.get(mididx - 1);
			int midrightval = mountainArr.get(mididx + 1);

			if (midleftval < midVal && midVal > midrightval)
			{
				return mididx;
			}
			else if (midleftval < midVal && midVal < midrightval) // leftside
			{
				return findPeak(mountainArr, mididx + 1, end);
			}
			else if (midleftval > midVal && midVal > midrightval) // right side
			{
				return findPeak(mountainArr, begin, mididx - 1);
			}
		}
		else if (begin == end)
		{
			return begin;
		}
	}
}

int binarySearchMountArr(MountainArray& mountainArr, int begin, int end, int target, bool isReversed = false)
{
	int len = end - begin + 1;

	if (len == 0 || (len == 1 && mountainArr.get(begin) != target))
	{
		return -1;
	}

	int mididx = (len - 1) / 2 + begin;

	if (mountainArr.get(mididx) == target)
	{
		if (mididx - 1 >= 0)
		{
			if (isReversed ? mountainArr.get(mididx - 1) > target : mountainArr.get(mididx - 1) < target)
			{
				return mididx;
			}
			else
			{
				return binarySearchMountArr(mountainArr, begin, mididx - 1, target, isReversed);
			}
		}
		else
		{
			return mididx;
		}
	}
	else if (mountainArr.get(mididx) > target)
	{
		if (!isReversed && mididx == begin)
		{
			return -1;
		}
		else
		{
			return isReversed ? binarySearchMountArr(mountainArr, mididx + 1, end, target, isReversed) : binarySearchMountArr(mountainArr, begin, mididx - 1, target, isReversed);
		}
	}
	else
	{
		return isReversed ? binarySearchMountArr(mountainArr, begin, mididx - 1, target, isReversed) : binarySearchMountArr(mountainArr, mididx + 1, end, target, isReversed);
	}
}


int findInMountainArray(int target, MountainArray& mountainArr) {
	int peak = findPeak(mountainArr, 0, mountainArr.length() - 1);
	int idx = binarySearchMountArr(mountainArr, 0, peak, target);

	if (idx != -1)
	{
		return idx;
	}
	else
	{
		int res = binarySearchMountArr(mountainArr, peak, mountainArr.length() - 1, target, true);
		return res;
	}
}

int main()
{
	testRun(findInMountainArray);

	return 0;
}