class Solution {
public:

    string longestCommonPrefix(vector<string>& strs)
    {
        stable_sort(strs.begin(), strs.end());

        string lcp;

        int i = 0;
        bool cont = true;
        while (cont)
        {
            for (int j = 0; cont && j < strs.size(); j++)
            {
                if (strs[j].length() >= i + 1)
                {
                    if (j != 0)
                    {
                        if (strs[j - 1][i] != strs[j][i])
                        {
                            cont = false;
                        }
                    }
                }
                else
                {
                    cont = false;
                }
            }

            if (cont)
            {
                lcp += strs[0][i];
                i++;
            }
        }

        return lcp;
    }

};