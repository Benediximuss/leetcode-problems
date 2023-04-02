#include <iostream>
#include <vector>

using namespace std;

void testRun(int (*fn)(vector<int>&, int))
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

    vector<testCase> cases = { { vector<int> {1,3,5,6}, 5 }, { vector<int> {1,3,5,6}, 2 }, { vector<int> {1,3,5,6}, 7 } };

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nNums = ", i + 1);
        printList(cases[i].nums);
        printf(", target = %d\n", cases[i].target);

        int output = fn(cases[i].nums, cases[i].target);

        printf("Output = %d\n\n", output);
    }

}


/* Solution part */
int findIndex(vector<int>& nums, int target, int begin, int end)
{
    int len = end - begin + 1;
    int mididx = (len - 1) / 2 + begin;

    if (target < nums[mididx])
    {
        if (mididx == 0)
        {
            return mididx;
        }
        else
        {
            if (target > nums[mididx - 1])
            {
                return mididx;
            }
            else
            {
                return findIndex(nums, target, begin, mididx - 1);
            }
        }
    }
    else if (target > nums[mididx])
    {
        if (mididx == nums.size() - 1)
        {
            return mididx + 1;
        }
        else
        {
            if (target < nums[mididx + 1])
            {
                return mididx + 1;
            }
            else
            {
                return findIndex(nums, target, mididx + 1, end);
            }
        }
    }
    else
    {
        return mididx;
    }

}

int searchInsert(vector<int>& nums, int target) {
    return findIndex(nums, target, 0, nums.size() - 1);
}

int main()
{
    testRun(searchInsert);

	return 0;
}
