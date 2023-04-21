class Solution {
public:

    void generate(string s, int l, int r, vector<string>& output)
    {
        if (l == r)
        {
            if (l == 0)
                output.push_back(s);
            else
                generate(s + '(', l - 1, r, output);
        }
        else if (l < r)
        {
            if (l != 0)
                generate(s + '(', l - 1, r, output);
            if (r != 0)
                generate(s + ')', l, r - 1, output);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> output;
        generate(string(), n, n, output);
        return output;
    }

};