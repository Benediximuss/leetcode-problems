# turns digits of an integer to reversed i.e = -1200 --> -21


def reversed(x):
    if str(x)[0] == "-":
        sign = "-"
        xx = str(x * -1)
    else:
        sign = "+"
        xx = str(x)

    rev = int(xx[::-1])

    if sign == "-":
        rev *= -1

    return rev


print(reversed(int(input("Enter a number: "))))
