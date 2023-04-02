#include <iostream>
#include <vector>

using namespace std;

void testRun(int (*fn)(vector<int>&))
{
    auto printList = [](vector<int> list) {
        printf("[");
        for (int i = 0; i < list.size(); i++)
        {
            printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
        }
        printf("]");
    };

    vector<vector<int>> cases = { {1,2,0}, {3,4,-1,1}, {7,8,9,11,12} };

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nNums = ", i + 1);
        printList(cases[i]);
        printf("\n");

        int output = fn(cases[i]);

        printf("Output = %d\n\n", output);
    }
}


/* Solution part */
int firstMissingPositive(vector<int>& nums)
{
    int posNums[100000] = { 0 };

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0 && nums[i] <= 100000)
        {
            posNums[(nums[i] - 1) % 100000] = nums[i];
        }
    }

    int result = 0;
    while (result < 100000 && posNums[result] > 0)
    {
        result++;
    }

    return result + 1;
}

int main()
{
    testRun(firstMissingPositive);

    return 0;
}
