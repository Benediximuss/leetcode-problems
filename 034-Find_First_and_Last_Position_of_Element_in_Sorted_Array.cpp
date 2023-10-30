#include <iostream>
#include <vector>

using namespace std;

void testRun(vector<int>(*fn)(vector<int>&, int))
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
        vector<int> nums;
        int target;
    };

    vector<testCase> cases = { {vector<int> {5,7,7,8,8,10}, 8}, {vector<int> {5,7,7,8,8,10}, 6}, {vector<int> {}, 0}, {vector<int> {1}, 1}, {vector<int> {2,2}, 2}};

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nNums = ", i + 1);
        printList(cases[i].nums);
        printf(", target = %d\n", cases[i].target);

        vector<int> output = fn(cases[i].nums, cases[i].target);

        printf("Output = ");
        printList(output);
        printf("\n\n");
    }
}


/* Solution part */

int findFirstPosition(vector<int>& nums, int& target, int begin, int end)
{
    int len = end - begin + 1;

    if (len == 0 || (len == 1 && nums[begin] != target))
    {
        return -1;
    }

    int mididx = (len - 1) / 2 + begin;


    if (nums[mididx] == target)
    {
        if (mididx - 1 >= 0)
        {
            if (nums[mididx - 1] < target)
            {
                return mididx;
            }
            else
            {
                return findFirstPosition(nums, target, begin, mididx - 1);
            }
        }
        else
        {
            return mididx;
        }
    }
    else if (nums[mididx] > target)
    {
        if (mididx == begin)
        {
            return -1;
        }
        else
        {
            return findFirstPosition(nums, target, begin, mididx - 1);
        }
    }
    else
    {
        return findFirstPosition(nums, target, mididx + 1, end);
    }
}

int findLastPosition(vector<int>& nums, int& target, int begin, int end)
{
    int len = end - begin + 1;

    if (len == 0 || (len == 1 && nums[begin] != target))
    {
        return -1;
    }

    int mididx = (len - 1) / 2 + begin;


    if (nums[mididx] == target)
    {
        if (mididx + 1 < nums.size())
        {
            if (nums[mididx + 1] > target)
            {
                return mididx;
            }
            else
            {
                return findLastPosition(nums, target, mididx + 1, end);
            }
        }
        else
        {
            return mididx;
        }
    }
    else if (nums[mididx] > target)
    {
        if (mididx == begin)
        {
            return -1;
        }
        else
        {
            return findLastPosition(nums, target, begin, mididx - 1);
        }
    }
    else
    {
        return findLastPosition(nums, target, mididx + 1, end);
    }
}

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> targetRange = { findFirstPosition(nums, target, 0, nums.size() - 1), findLastPosition(nums, target, 0, nums.size() - 1) };

    return targetRange;
}

int main()
{
	testRun(searchRange);

	return 0;
}