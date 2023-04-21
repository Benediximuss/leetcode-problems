class Solution {
public:

    char complement(const char a)
    {
        if (a == ')')
        {
            return '(';
        }
        else if (a == ']')
        {
            return '[';
        }
        else if (a == '}')
        {
            return '{';
        }

        return -1;
    }

    bool isValid(string s)
    {
        string stack;

        for (int i = 0; i < s.length() && stack.length() <= s.length() - i; i++)
        {
            if (stack.back() == complement(s[i]))
            {
                stack.pop_back();
            }
            else
            {
                stack += s[i];
            }
        }

        if (stack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};