#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

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

    vector<vector<int>> cases = { {4,2,5,3}, {1,2,3,5,6}, {1,10,100,1000}, {8,5,9,9,8,4}, {4,5,8,8,8,9,9}, {1,2,3,10,20}, {18,24,26,28,29,33,33,35,41,47} };

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nNums = ", i + 1);
        printList(cases[i]);
        printf("\n");

        int output = fn(cases[i]);

        printf("Output = %d\n\n", output);
    }
}

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

int minOperations(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int max = nums[n - 1];

    vector<int> uniqueNums;

    uniqueNums.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            uniqueNums.push_back(nums[i]);
        }
    }

    int min = INT_MAX;

    for (int i = 0; i < uniqueNums.size() && min > 0; i++)
    {
        int left = uniqueNums[i];
        int right = left + n - 1;
        int temp;

        if (right > max)
        {
            int current = uniqueNums.size() - 1 - i;
            current += 1 + 0;
            temp = n - current;
        }
        else if (right == max)
        {
            int current = uniqueNums.size() - 1 - i - 1;
            current += 1 + 1;
            temp = n - current;
        }
        else
        {
            int rightidx = findIndex(uniqueNums, right, 0, uniqueNums.size() - 1);
            if (uniqueNums[rightidx] == right)
            {
                int current = rightidx - i - 1;
                current += 1 + 1;
                temp = n - current;
            }
            else
            {
                int current = rightidx - i - 1;
                current += 1 + 0;
                temp = n - current;
            }
        }

        min = temp < min ? temp : min;
    }

    return min;
}

int main()
{
	testRun(minOperations);

	return 0;
}