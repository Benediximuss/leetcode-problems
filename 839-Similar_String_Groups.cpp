class Solution {
public:

    bool isSimilar(const string& str1, const string& str2)
    {
        int diff = 0;


        for (int i = 0; i < str1.length() && diff < 3; i++)
        {
            if (str1[i] != str2[i])
            {
                diff++;
            }
        }

        return diff <= 2 ? true : false;
    }

    void lookGroup(vector<string>& strs, string current)
    {
        for (int i = strs.size() - 1; i >= 0; i--)
        {
            if (strs[i] != "-1" && isSimilar(strs[i], current))
            {
                string temp = strs[i];
                strs[i] = "-1";
                lookGroup(strs, temp);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs)
    {
        int output = 0;
        for (int i = strs.size() - 1; i >= 0; i--)
        {
            if (strs[i] != "-1")
            {
                string temp = strs[i];
                strs[i] = "-1";
                lookGroup(strs, temp);
                output++;
            }
        }

        return output;
    }

};