n = int(input())
s = input()
count = 0
i = 0
while i < n:
    run_length = 1
    while i + run_length < n and s[i + run_length] == s[i]:
        run_length += 1
    count += run_length // 2
    i += run_length
print(count)
