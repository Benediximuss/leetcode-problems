#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testRun(vector<int>(*fn)(vector<int>&, vector<int>&, long long))
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
        vector<int> spells;
        vector<int> pots;
        int success;
    };

    vector<testCase> cases = { { vector<int> {5,1,3}, vector<int> {1,2,3,4,5}, 7 }, { vector<int> {3,1,2}, vector<int> {8,5,8}, 16 }, { vector<int> {38,11}, vector<int> {3,20}, 1065 } };

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nSpells = ", i + 1);
        printList(cases[i].spells);
        printf(", Potions = ");
        printList(cases[i].pots);
        printf(", Success = %d\n", cases[i].success);

        vector<int> output = fn(cases[i].spells, cases[i].pots, cases[i].success);

        printf("Output = ");
        printList(output);
        printf("\n\n");
    }
}


/* Solution part */

int findIndex(vector<int>& nums, double target, int begin, int end)
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

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
{
    vector<int> output(spells.size());

    sort(potions.begin(), potions.end()); 

    for (int i = 0; i < spells.size(); i++)
    {
        double target = (double)success / spells[i];
        int targetIdx = findIndex(potions, target, 0, potions.size() - 1);

        if (target == (long int)target / 1 && targetIdx < potions.size())
        {
            int temp = targetIdx;
            while (potions[temp] == target)
            {
                int temp = findIndex(potions, target, 0, targetIdx - 1);
                if (temp <= targetIdx - 1)
                {
                    targetIdx = temp;
                }
                else
                {
                    break;
                }
            }
        }

        output[i] = potions.size() - targetIdx;
    }

    return output;
}


int main()
{

    testRun(successfulPairs);

    return 0;
}
