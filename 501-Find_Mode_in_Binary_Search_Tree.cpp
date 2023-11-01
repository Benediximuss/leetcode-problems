class Solution2 {
public:
	unordered_map<int, int> memo;

	void count(TreeNode* node)
	{
		if (!node)
			return;

		auto it = memo.find(node->val);
		if (it == memo.end())
			memo[node->val] = 1;
		else
			it->second++;

		count(node->left);
		count(node->right);
	}

	vector<int> findMode(TreeNode* root)
	{
		count(root);

		int maxCount = -1;
		vector<int> ans;

		for (const pair<int, int>& hashpair : memo)
		{
			if (hashpair.second > maxCount)
			{
				maxCount = hashpair.second;

				ans.clear();
				ans.push_back(hashpair.first);
			}
			else if (hashpair.second == maxCount)
			{
				ans.push_back(hashpair.first);
			}
		}

		return ans;
	}
};