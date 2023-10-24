/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void findMaxs(vector<int>& maxs, TreeNode* ptr, int row)
    {
        if (!ptr)
            return;

        if (maxs.size() < row + 1)
            maxs.resize(row + 1, INT_MIN);

        maxs[row] = max(maxs[row], ptr->val);

        findMaxs(maxs, ptr->right, row + 1);
        findMaxs(maxs, ptr->left, row + 1);
    }
    
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> maxs;
        findMaxs(maxs, root, 0);

        return maxs;
    }
};