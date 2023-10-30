#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Solution part */

class Solution {
public:

	vector<int> sortByBits(vector<int>& arr)
	{
		sort(arr.begin(), arr.end(), Solution::customComparator);

		return arr;
	}

private:

	static int countBinaryOnes(int dec)
	{
		int count = 0;

		while (dec > 0)
		{
			if ((dec & 1) == 1)
				count++;
			dec >>= 1;
		}

		return count;
	}

	static bool customComparator(const int& a, const int& b) {
		int count1 = countBinaryOnes(a);
		int count2 = countBinaryOnes(b);

		if (count1 == count2)
			return a < b;
		else
			return count1 < count2;

	};

};


/* Testing Function */

void testRun(vector<int> (Solution::*fn)(vector<int>&))
{
	auto printList = [](vector<int> list) {
		printf("[");
		for (int i = 0; i < list.size(); i++)
		{
			printf("%d%c", list[i], (i < list.size() - 1) ? ',' : '\0');
		}
		printf("]");
	};

	vector<vector<int>> cases = { {7, 0, 5} , {0,1,2,3,4,5,6,7,8} , {1024,512,256,128,64,32,16,8,4,2,1} };

	for (int i = 0; i < cases.size(); i++)
	{
		printf("Case %d\narr = ", i + 1);
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
	testRun(&Solution::sortByBits);

    return 0;
}