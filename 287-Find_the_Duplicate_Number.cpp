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

    vector<vector<int>> cases = { {1,3,4,2,2}, {3,1,3,4,2}, {6,4,2,3,5,7,4,1} };

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

int findDuplicate(vector<int>& nums) {

    vector<int> counts(nums.size() - 1, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        counts[nums[i] - 1]++;
    }

    int res = 0;

    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] > 1)
        {
            res = i + 1;
        }
    }

    return res;
}

int main()
{
    testRun(findDuplicate);

    return 0;
}
