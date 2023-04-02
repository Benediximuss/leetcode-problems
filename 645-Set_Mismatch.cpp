#include <iostream>
#include <vector>

using namespace std;

void testRun(vector<int>(*fn)(vector<int>&))
{
    auto printList = [](vector<int> list) {
        printf("[");
        for (int i = 0; i < list.size(); i++)
        {
            printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
        }
        printf("]");
    };

    vector<vector<int>> cases = { {1,2,2,4}, {1,1}, {6,8,2,3,5,3,4,1} };

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nNums = ", i + 1);
        printList(cases[i]);
        printf("\n");

        vector<int> output = fn(cases[i]);

        printf("Output = ");
        printList(output);
        printf("\n\n");
    }
}


/* Solution part */

vector<int> findErrorNums(vector<int>& nums) {

    vector<int> counts(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
        counts[nums[i] - 1]++;
    }

    vector<int> res(2);

    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] == 0)
        {
            res[1] = i + 1;
        }
        else if (counts[i] == 2)
        {
            res[0] = i + 1;
        }
    }

    return res;
}

int main()
{
    testRun(findErrorNums);

    return 0;
}
