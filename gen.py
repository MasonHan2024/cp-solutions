tests = []
budget = SUM_N
while budget >= 2:
    n = 2 * random.randint(1, min(5, budget // 2))   # small even n
    budget -= n
    tests.append(n)
print(len(tests))
for n in tests:
    print(n, random.randint(1, n))
    print(*[random.randint(0, n) for _ in range(n)])    