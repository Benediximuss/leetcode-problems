# Returns the first integer in a string i.e : string = "    -123124_Asfda_ 1234143123" output is -123124

def fn(s):
    k = 0
    for i in range(len(s)):
        if s[i] == " ":
            k += 1
        else:
            break

    a = s.replace(" ", "", k)

    if a == "":
        return 0

    x = ""

    for i in range(len(a)):
        if i == 0:
            if a[0].isnumeric() == True or a[0] == "+" or a[0] == "-":
                x += a[0]
            else:
                return 0
                break
        else:
            if a[i].isnumeric() == True:
                x += a[i]
            else:
                break

    if x == "-" or x == "+":
        return 0

    return int(x)


print(fn("     -121231352123124asdasdasd8uasdi u1928u iajsd"))
