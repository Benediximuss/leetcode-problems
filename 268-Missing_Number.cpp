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

    vector<vector<int>> cases = { {3,0,1}, {0,1}, {9,6,4,2,3,5,7,0,1} };

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

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;

    for (int i = 0; i < n; i++)
    {
        sum -= nums[i];
    }

    return sum;
}

int main()
{
    testRun(missingNumber);

    return 0;
}
