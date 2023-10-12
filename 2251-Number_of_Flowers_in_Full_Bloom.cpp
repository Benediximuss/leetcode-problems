#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testRun(vector<int>(*fn)(vector<vector<int>>&, vector<int>&))
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
        vector<vector<int>> flowers;
        vector<int> people;
    };

    vector<testCase> cases = { { { {1,6} ,{3,7},{9,12},{4,13}} , {2,3,7,11} } , { {{1,10}, {3,3}} , {3,3,2} }};

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nFlowers = [", i + 1);
        for (int j = 0; j < cases[i].flowers.size(); j++)
        {
            printList(cases[i].flowers[j]);
            printf("%c", (j == cases[i].flowers.size() - 1) ? ']' : ',');
        }
        printf(", people = ");
        printList(cases[i].people);
        printf("\n");

        vector<int> output = fn(cases[i].flowers, cases[i].people);

        printf("Output = ");
        printList(output);
        printf("\n\n");
    }
}


/* Solution part */

void sortFlowersByEndingTime(vector<vector<int>>& flowers)
{
    auto customComparator = [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // by the second element
    };

    sort(flowers.begin(), flowers.end(), customComparator);
}

int findFirstPosition(vector<vector<int>>& nums, int& target, int begin, int end, int time)
{
    int len = end - begin + 1;

    if (len == 0 || (len == 1 && nums[begin][time] != target))
    {
        return -1;
    }

    int mididx = (len - 1) / 2 + begin;


    if (nums[mididx][time] == target)
    {
        if (mididx - 1 >= 0)
        {
            if (nums[mididx - 1][time] < target)
            {
                return mididx;
            }
            else
            {
                return findFirstPosition(nums, target, begin, mididx - 1, time);
            }
        }
        else
        {
            return mididx;
        }
    }
    else if (nums[mididx][time] > target)
    {
        if (mididx == begin)
        {
            return -1;
        }
        else
        {
            return findFirstPosition(nums, target, begin, mididx - 1, time);
        }
    }
    else
    {
        return findFirstPosition(nums, target, mididx + 1, end, time);
    }
}

int findIndex(vector<vector<int>>& nums, int& target, int begin, int end, int time)
{
    int len = end - begin + 1;
    int mididx = (len - 1) / 2 + begin;

    if (target < nums[mididx][time])
    {
        if (mididx == 0)
        {
            return mididx;
        }
        else
        {
            if (target > nums[mididx - 1][time])
            {
                return mididx;
            }
            else
            {
                return findIndex(nums, target, begin, mididx - 1, time);
            }
        }
    }
    else if (target > nums[mididx][time])
    {
        if (mididx == nums.size() - 1)
        {
            return mididx + 1;
        }
        else
        {
            if (target < nums[mididx + 1][time])
            {
                return mididx + 1;
            }
            else
            {
                return findIndex(nums, target, mididx + 1, end, time);
            }
        }
    }
    else
    {
        return mididx;
    }

}

int countForTimeT(vector<vector<int>>& byStart, vector<vector<int>>& byEnd, int timeT)
{
    int target = timeT + 1;
    int started = findFirstPosition(byStart, target, 0, byStart.size() - 1, 0);
    if (started == -1)
    {
        started = findIndex(byStart, target, 0, byStart.size() - 1, 0);
    }

    int ended = findFirstPosition(byEnd, timeT, 0, byEnd.size() - 1, 1);
    if (ended == -1)
    {
        ended = findIndex(byEnd, timeT, 0, byEnd.size() - 1, 1);
    }

    return started - ended;
}

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

    vector<vector<int>> flowers2 = flowers;

    sort(flowers.begin(), flowers.end());
    sortFlowersByEndingTime(flowers2);

    vector<int> output(people.size());

    for (int i = 0; i < people.size(); i++)
    {
        output[i] = countForTimeT(flowers, flowers2, people[i]);
    }

    return output;
}

int main()
{
	testRun(fullBloomFlowers);


	return 0;
}

