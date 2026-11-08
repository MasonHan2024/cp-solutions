import random, sys

seed = int(sys.argv[1]) if len(sys.argv) > 1 else 0
random.seed(seed)                      



t = random.randint(1, int(10e+4))
print(str(t) + '\n')
for _ in range(t):
    n = 2*random.randint(1, int(10e+5))         
    k = random.randint(1, n)
    print(str(n) + " "+ str(k)+'\n')
    print(*[random.randint(0, n) for _ in range(n)] + '\n')