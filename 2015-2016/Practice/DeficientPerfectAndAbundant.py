N = int(raw_input())

for i in range(N):
    num = int(raw_input())

    divSum = 1

    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            divSum += i

            if (i != num / i):
                divSum += num / i

    if divSum == num:
        print num, "is a perfect number."
    elif divSum < num:
        print num, "is a deficient number."
    elif divSum > num:
        print num, "is an abundant number."
