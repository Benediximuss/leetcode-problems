class UnionFind {

	public:

		UnionFind(int n)
			: parent(n)
		{
			iota(begin(parent), end(parent), 0);
		}
		
		int find(int a)
		{
			return parent[a] == a ? a : (parent[a] = find(parent[a]));
		}

		void unify(int a, int b)
		{
            int ap = find(a), bp = find(b);
            if (ap != bp)
            {
			    parent[find(b)] = find(a);
            }
		}

		bool isUnion(int a, int b)
		{
			return find(a) == find(b);
		}

	private:
		vector<int> parent;

};

class Solution {
public:
    static bool weightComp(vector<int>& a, vector<int>& b)
    {
        return a[2] < b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries)
    {
        vector<bool> output(queries.size());

        for (int i = 0; i < queries.size(); i++)
        {
            queries[i].push_back(i);
        }

        sort(begin(queries), end(queries), weightComp);
        sort(begin(edgeList), end(edgeList), weightComp);

        UnionFind unionFind(n);

        int j = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            int& lim = queries[i][2];

            while (j < edgeList.size() && edgeList[j][2] < lim)
            {
                unionFind.unify(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            output[queries[i][3]] = unionFind.isUnion(queries[i][0], queries[i][1]);
        }

        return output;
    }

};