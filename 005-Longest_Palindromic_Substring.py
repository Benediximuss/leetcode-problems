# finds the longest palindromic substring in given string

def longestPalindrome(s):
    max = ""
    for i in range(len(s)):
        pp = []
        k = i
        while k != len(s):
            pp.append(s[k])
            if k != len(s) - 1:
                k += 1
            else:
                break

        k = 0
        while k != len(pp):
            t = ""
            for i in range(k+1):
                t += pp[i]

            if t == t[::-1]:
                if len(t) > len(max):
                    max = t

            k += 1
    return max


xxx = "bananadflwKİEP,qşwdaşswdkickstartstrats,iqlwğeq123456789benbirdavarım0987654321aa"
print(longestPalindrome(xxx))
