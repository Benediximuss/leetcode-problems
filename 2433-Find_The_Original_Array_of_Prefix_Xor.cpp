#include <iostream>
#include <vector>

using namespace std;

/* Solution part */

class Solution {
public:
	vector<int> findArray(vector<int>& pref)
	{
		vector<int> ans(pref.size());

		ans[0] = pref[0];

		for (int i = 1; i < ans.size(); i++)
		{
			ans[i] = pref[i - 1] ^ pref[i];
		}

		return ans;
	}
};


/* Testing Function */

void testRun(vector<int>(Solution::*fn)(vector<int>&))
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	vector<vector<int>> cases = { {5,2,0,3,1} , {13} , {4, 2, 13, 56, 3} };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\npref = ", i + 1);
		printList(cases[i]);
		printf("\n");

		vector<int> output = (Solution().*fn)(cases[i]);

		printf("Output: "); 
		printList(output);
		printf("\n\n");
	}

}


int main()
{
	testRun(&Solution::findArray);

    return 0;
}