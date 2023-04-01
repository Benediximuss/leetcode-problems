# Checks whether a number is a palindrome or not.

def isPalindrome(x):

    if x < 0:
        print("Not a palindrome!")
    else:
        hane = 0
        while True:  # KAÇ HANELİ FONKSİYONU
            if x/10**hane >= 1:
                hane += 1
            else:
                print(x, "has", hane, "decimals")
                break

        check = 1
        k = 1
        while k != hane//2 + 1:
            if x % 10**k // 10**(k-1) == x % 10**(hane-k+1) // 10**(hane-k):
                k += 1
            else:
                check = 0
                break

        if check == 0:
            print("Not a palindrome!")
        else:
            print("Is a palindrome!")


isPalindrome(int(input("Enter a number: ")))
