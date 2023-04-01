# finds the longest substring which does not repeat any single character
# 2260 ms % 8,52

def lengthOfLongestSubstring(s):
    max = 0
    ss = len(s)
    for i in range(ss):
        if ss - i <= max:
            break
        else:
            k = i + 1
            while k != ss:
                if s[i:k].count(s[k]) == 0:
                    k += 1
                else:
                    break
            if k-i > max:
                max = k-i

    return max


string = "pwwkew"

print(lengthOfLongestSubstring(string))
