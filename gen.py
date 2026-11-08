import random, sys
random.seed(int(sys.argv[1]))
n = random.randint(2, 50)          # check the statement's minimum n
print(1)
print(n)
print(*[random.randint(-5, 5) for _ in range(n)])