class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int product = 1;
        int hasZero = 0;
        bool hasNonZero = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                product *= nums[i];
                hasNonZero = true;
            }
            else
                hasZero++;
        }


        if (hasNonZero)
        {
            vector<int> result(nums.size());
            for (int i = 0; i < nums.size(); i++)
            {   
                if (nums[i] == 0)
                {
                    if (hasZero > 1)
                        result[i] = 0;
                    else
                        result[i] = product;
                }
                else
                {
                    if (hasZero > 0)
                    {
                        result[i] = 0;
                    }
                    else
                    {
                        result[i] = product/nums[i];
                    }
                }
            }

            return result;
        }
        else
        {
            return vector<int>(nums.size(), 0);
        }
    }
};