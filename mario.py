from cs50 import get_int

i = get_int("Height: ")
if i < 1 and i > 8:
    i = get_int("Height:")

k = 1
h = i - 1
while k <= i and h >= 0:
    for j in range(i):
        print(" "*h + "#"*k)
        k = k + 1
        h = h - 1
