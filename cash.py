from cs50 import get_float

cash = get_float("Change owed: ")

c = round(cash * 100)
change = 0
while c > 0:
    if c >= 25:
        c-= 25
        change+= 1
    elif c >= 10:
        c-= 10
        change+= 1
    elif c >= 5:
        c-= 5
        change+= 1
    elif c >= 1:
         c-= 1
         change+= 1
print(change)
