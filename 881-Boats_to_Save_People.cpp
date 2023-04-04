#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testRun(int(*fn)(vector<int>&, int))
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
        vector<int> people;
        int limit;
    };

    vector<testCase> cases = { {{1, 2}, 3}, {{3, 2, 2, 1}, 3}, {{3, 5, 3, 4}, 5} };

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nPeople = ", i + 1);
        printList(cases[i].people);
        printf(", Limit = %d\n", cases[i].limit);

        int output = fn(cases[i].people, cases[i].limit);

        printf("Output = %d\n", output);
        printf("\n\n");
    }
}

/* Solution part */

int numRescueBoats(vector<int>& people, int limit)
{
    stable_sort(people.begin(), people.end());

    int res = 0;
    vector<int> counts(people[people.size() - 1] + 1, -1);
    counts[0] = people.size();

    for (int templimit = people[people.size() - 1]; templimit > 0 && people.size() > 0; templimit--)
    {

        if (counts[templimit] == -1)
        {
            counts[templimit] = 0;
            auto range = equal_range(people.begin(), people.end(), templimit);
            for (auto it = range.first; it != range.second; ++it)
            {
                counts[templimit]++;
            }
        }
        
        while (counts[templimit] > 0)
        {
            counts[templimit]--;

            bool compFound = false;
            for (int k = (templimit >= (limit + 1) / 2 ? limit - templimit : templimit); k >= 0 && !compFound; k--)
            {
                if (counts[k] == -1)
                {
                    counts[k] = 0;
                    auto range = equal_range(people.begin(), people.end(), k);
                    for (auto it = range.first; it != range.second; ++it)
                    {
                        counts[k]++;
                    }
                   
                }

                if (counts[k] > 0)
                {
                    res++;
                    compFound = true;
                    counts[k]--;
                }
            }

            if (!compFound)
            {
                res++;
            }
        }

    }

    return res;
}

int main()
{
    testRun(numRescueBoats);

    return 0;
}
