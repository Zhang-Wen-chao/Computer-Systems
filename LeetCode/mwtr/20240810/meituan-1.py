def has_even_factor(x):
    if x % 2 == 0:
        return "YES"
    else:
        return "NO"
    
T = int(input())
results = []

for i in range(T):
    x = int(input())
    results.append(has_even_factor(x))

for result in results:
    print(result)