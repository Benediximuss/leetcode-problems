#include <iostream>
#include <vector>

using namespace std;

void testRun(int (*fn)(int))
{
    vector<int> cases = { 2, 3, 6 };

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nn = %d\n", i + 1, cases[i]);

        int output = fn(cases[i]);

        printf("Output = %d\n\n", output);
    }
}


/* Solution part */
int climbStairsMemo(int n, int* memo)
{
    if (memo[n] == -1)
    {
        memo[n] = climbStairsMemo(n - 1, memo) + climbStairsMemo(n - 2, memo);
    }

    return memo[n];
}

int climbStairs(int n)
{
    int* memo = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        memo[i] = -1;
    }

    memo[0] = 1;
    memo[1] = 1;

    int output = climbStairsMemo(n, memo);

    delete[] memo;

    return output;
}

int main()
{
    testRun(climbStairs);

    return 0;
}
