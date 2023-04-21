class Solution {
public:

    void combs(const vector<vector<char>>& dict, vector<string>& output, const string& digits, int left, string& pre)
    {
        const vector<char>& temp = dict[digits[left] - 50];
        for (int i = 0; i < temp.size(); i++)
        {
            if (left == digits.length() - 1)
            {
                output.push_back(pre + dict[digits[left] - 50][i]);
            }
            else
            {
                pre += temp[i];
                combs(dict, output, digits, left + 1, pre);
                pre.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<vector<char>> dict = { {'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r', 's'}, {'t','u','v'}, {'w','x','y','z'} };

        vector<string> output;

        if (digits.length() > 0)
        {
            string pre;
            combs(dict, output, digits, 0, pre);
        }

        return output;
    }

};