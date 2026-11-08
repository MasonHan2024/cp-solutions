import random, sys

seed = int(sys.argv[1]) if len(sys.argv) > 1 else 0
random.seed(seed)                      # same seed → same test, so you can reproduce a failure

t = 1
print(t)
for _ in range(t):
    n = random.randint(6, 10)          # small n for stress tests
    print(n)
    print(*[random.randint(-3, 3) for _ in range(n)])