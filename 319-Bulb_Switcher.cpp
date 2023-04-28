/*
    Approach 1 : Brute force
*/
class Solution1 {
public:

    void toggle(vector<bool>& bulbs, int x, int& on)
    {
        if (bulbs[x])
        {
            bulbs[x] = false;
            on--;
        }
        else
        {
            bulbs[x] = true;
            on++;
        }
    }

    int bulbSwitch(int n) {
        vector<bool> bulbs(n, true);
        int on = n;

        for (int i = 1; i < n; i++)
        {
            int j = i;
            while (j < n)
            {
                toggle(bulbs, j, on);
                j += i + 1;
            }
        }

        return on;
    }

};

/* 
    Approach 2 : 
    Find positive divisors of all bulbs, if it is odd add 1 to the result,
    since a bulb, initially off and toggled odd times, will be on at the
    end no matter how many times it is toggled
*/
class Solution2 {
public:

    // Count positive divisors of number n
    int tau(int n) {
        int count = 0;
        double sqrtN = sqrt(n);

        for (int i = 1; i <= sqrtN; i++) {
            if (n % i == 0) {
                // Counting two divisors: i and n/i
                count += 2;

                // If i is the square root of n, we count it only once
                if (i == sqrtN)
                    count--;
            }
        }

        return count;
    }

    int bulbSwitch(int n)
    {
        int output = 0;

        for (int i = 0; i < n; i++)
        {
            if (tau(i + 1) % 2 == 1)
            {
                output++;
            }
        }

        return output;
    }

};


/*
    Approach 3 : Constant time
    Since we only care about whether an integer has a odd or even number of positive
    divisors, instead of wasting time counting the positive divisors of the integer
    representing each light bulb, we can look at whether they are perfect squares or
    not, because only the perfect square integers have an odd number of positive divisors.
    As for counting perfect squares from 1 to n, square root of n (truncated if not integer)
    would give the number of perfect square integers in the range [1, n].
    
*/
class Solution3 {
public:

    int bulbSwitch(int n)
    {
        return sqrt(n);
    }
  
};