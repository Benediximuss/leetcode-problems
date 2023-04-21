class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maxVol = 0;
        while(i < j)
        {
            int vol = (j - i) * min(height[i], height[j]);
            maxVol = max(vol, maxVol);

            if (height[i] <= height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return maxVol;
    }
};