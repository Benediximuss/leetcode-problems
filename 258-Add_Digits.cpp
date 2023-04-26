class Solution {
public:

    int digits(const int& x)
    {
        return x == 0 ? 1 : log10(x) + 1;
    }

    int sumofdigits(int x)
    {
        int sum = 0;
        int temp = x;
        int k = digits(x) - 1;
        while (k >= 0)
        {
            int power = pow(10,k);
            sum += temp / power;
            temp = temp % power;
            k--;
        }
        return sum;
    }

    int addDigits(int num)
    {
        if (num < 10)
        {
            return num;
        }
        else
        {
            return addDigits(sumofdigits(num));
        }
    }
};