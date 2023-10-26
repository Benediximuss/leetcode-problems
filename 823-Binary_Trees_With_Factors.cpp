#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* Solution part */

class Solution {
public:

    int numFactoredBinaryTrees(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
 
        for (int i = 0; i < arr.size(); i++)
        {
            int& product = arr[i];

            int k = findIndex(arr, product / 2 + 1, 0, arr.size() - 1);

            for (int j = 0; j < k; j++)
            {
                int& factor1 = arr[j];

                if (product % factor1 == 0)
                {
                    int factor2 = product / factor1;
                    if (factor2 == factor1)
                    {
                        factors[product].push_back(make_pair(factor1, factor1));
                    }
                    else
                    {
                        int factoridx = findIndex(arr, factor2, j, k);

                        if (arr[factoridx] == factor2)
                        {
                            factors[product].push_back(make_pair(factor1, factor2));
                            factors[product].push_back(make_pair(factor2, factor1));

                            k = factoridx;
                        }
                    }
                }
            }
        }

        int mod = 1e9 + 7;

        int ans = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            ans = (ans + countTrees(arr[i], mod)) % mod;
        }

        return ans;
    }

private:

    unordered_map<int, vector<pair<int, int>>> factors;
    unordered_map<int, int> dp;

    int countTrees(int root, const int mod)
    {
        if (dp.find(root) != dp.end())
            return dp[root];

        int res;

        vector<pair<int, int>>& temp = factors[root];

        if (temp.empty())
            res = 1;
        else
        {
            int tempsum = 0;
            for (int i = 0; i < temp.size(); i++)
            {
                int left = countTrees(temp[i].first, mod) % mod;
                int right = countTrees(temp[i].second, mod) % mod;

                tempsum = (left * right + tempsum) % mod;
            }

            res = tempsum + 1;
        }

        dp[root] = res;

        return res % mod;
    }


    int findIndex(vector<int>& nums, int target, int begin, int end)
    {
        int len = end - begin + 1;
        int mididx = (len - 1) / 2 + begin;

        if (target < nums[mididx])
        {
            if (mididx == begin)
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
            if (mididx == end)
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
            if (mididx - 1 >= 0)
            {
                if (nums[mididx - 1] < target)
                {
                    return mididx;
                }
                else
                {
                    return findIndex(nums, target, begin, mididx - 1);
                }
            }
            else
            {
                return mididx;
            }
        }

    }

};


/* Testing Function */

void testRun(int (Solution::*fn)(vector<int>&))
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

    vector<vector<int>> cases = { {2, 4} , {2, 4, 5, 10} , {2, 4, 5, 10, 20, 40} , {15, 13, 22, 7, 11} };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\narr = ", i + 1);
		printList(cases[i]);
		printf("\n");

		int output = (Solution().*fn)(cases[i]);

		printf("Output: %d\n\n", output);
	}

}


int main()
{
	testRun(&Solution::numFactoredBinaryTrees);

    return 0;
}