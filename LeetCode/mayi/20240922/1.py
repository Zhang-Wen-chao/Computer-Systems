T = int(input())
for _ in range(T):
    n, m, k = map(int, input().split())
    n, m, k = int(n), int(m), int(k)
    found = False
    for c in range(100, 0, -1):  # Prioritize larger c
        total_c = c * k
        if total_c > 100:
            continue
        for a in range(1, 101):
            total_a = a * n
            total_remaining = 100 - total_c - total_a
            if total_remaining < 0:
                break  # No need to check larger a
            if m == 0:
                if total_remaining == 0:
                    b = 1  # Any value between 1 and 100
                    print("YES")
                    print(f"{a} {b} {c}")
                    found = True
                    break
                else:
                    continue
            else:
                if total_remaining % m == 0:
                    b = total_remaining // m
                    if 1 <= b <= 100:
                        print("YES")
                        print(f"{a} {b} {c}")
                        found = True
                        break
        if found:
            break
    if not found:
        print("NO")
