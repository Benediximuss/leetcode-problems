class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);

        int pre = 0;
        for (int i = 0; i < n; i++)
        {
            leftSum[i] = pre;
            pre += nums[i];
        }

        int post = 0;
        for (int i = n-1; i >= 0; i--)
        {
            rightSum[i] = post;
            post += nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (leftSum[i] == rightSum[i])
                return i;
        }

        return -1;
    }
};