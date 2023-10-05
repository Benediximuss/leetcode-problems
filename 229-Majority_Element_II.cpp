#include <iostream>
#include <vector>
#include <map>

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

    vector<vector<int>> cases = { {3,2,3}, {1}, {1,2} };

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

vector<int> majorityElement(vector<int>& nums) {

    map<int, int> dict;
    vector<int> out;

    int k = nums.size() / 3;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!dict.count(nums[i]))
        {
            dict[nums[i]] = 1;
        }
        else
        {
            dict[nums[i]] += 1;
        }

        if (dict[nums[i]] == k+1)
        {
            out.push_back(nums[i]);
            dict[nums[i]] += 1;
        }
    }

    return out;
}

int main()
{
	testRun(majorityElement);

	return 0;
}