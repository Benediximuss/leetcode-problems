#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void testRun(vector<vector<int>> (*fn)(vector<int>& nums))
{
    auto printList = [](vector<int> list) {
        printf("[");
        for (int i = 0; i < list.size(); i++)
        {
            printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
        }
        printf("]");
    };

    vector<vector<int>> cases = { {-1,0,1,2,-1,-4}, {0,1,1}, {0,0,0} };

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nNums = ", i + 1);
        printList(cases[i]);
        printf("\n");

        vector<vector<int>> output = fn(cases[i]);

        printf("Output = [%c", (output.size() == 0) ? ']' : '\0');
        for (int j = 0; j < output.size(); j++)
        {
            printList(output[j]);
            printf("%s", (j < output.size() - 1) ? " , " : "]");
        }

        printf("\n\n");
    }

}

/* Solution part */
vector<vector<int>> threeSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    map<vector<int>, bool> hash;

    map<int, bool> hash_X;

    for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
    {
        int& x = nums[i];

        if (!hash_X.count(x))
        {
            for (int j = i + 1; j < nums.size() && nums[j] <= 0 - x; j++)
            {
                int& y = nums[j];
                int target_z = 0 - (x + y);

                if (binary_search(nums.begin() + j + 1, nums.end(), target_z))
                {
                    vector<int> temp = { x, y, target_z };

                    if (!hash.count(temp))
                    {
                        hash[temp] = true;
                        res.push_back(temp);
                    }
                }

            }
            hash_X[x] = true;
        }
    }

    return res;
}

int main()
{

    testRun(threeSum);

	return 0;
}
