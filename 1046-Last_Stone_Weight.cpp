class Solution {
public:

    int lastStoneWeight(vector<int>& stones)
    {
        bool init = true;
        while (stones.size() > 1)
        {
            if (stones[stones.size()-1] < stones[stones.size()-2] || init)
            {
                sort(stones.begin(), stones.end());
                init = false;
            }

            if (stones[stones.size()-1] == stones[stones.size()-2])
            {
                stones.pop_back();
                stones.pop_back();
            }
            else
            {
                stones[stones.size()-2] = stones[stones.size()-1] - stones[stones.size()-2];
                stones.pop_back();
            }
        }

        return stones.size() == 0 ? 0 : stones.front();
    }
    
};