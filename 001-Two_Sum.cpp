#include <iostream>
#include <vector>
#include <map>

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

    vector<testCase> cases = { { vector<int> {2,7,11,15}, 9 }, { vector<int> {3,2,4}, 6 }, { vector<int> {3,3}, 6 } };

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

vector<int> twoSum(vector<int>& nums, int target)
{
    map<int, int> hash;

    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (hash.count(target - nums[i]) && hash[target - nums[i]] != i)
        {
            return vector<int> {i, hash[target - nums[i]]};
        }
    }

    return vector<int> {-1, -1};
}

int main()
{
    testRun(twoSum);

    return 0;
}
