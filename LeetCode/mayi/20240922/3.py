import sys
import threading

def main():
    import sys
    sys.setrecursionlimit(1 << 25)
    input = sys.stdin.readline

    N = 10**7 + 200

    spf = [0] * (N + 1)
    for i in range(2, N + 1):
        if spf[i] == 0:
            spf[i] = i
            if i * i <= N:
                for j in range(i * i, N + 1, i):
                    if spf[j] == 0:
                        spf[j] = i

    T = int(input())
    test_cases = []
    nums_to_factorize = set()

    for _ in range(T):
        x_str, t_str = input().split()
        x = int(x_str)
        t = int(t_str)
        l = max(1, x - t)
        r = x + t
        nums = []
        for n in range(l, r + 1):
            nums.append(n)
            nums_to_factorize.add(n)
        test_cases.append((nums, x, t))

    max_exponent_dict = {}

    for n in nums_to_factorize:
        temp_n = n
        max_exp = 0
        while temp_n > 1:
            p = spf[temp_n]
            e = 0
            while temp_n % p == 0:
                temp_n //= p
                e += 1
            if e > max_exp:
                max_exp = e
        max_exponent_dict[n] = max_exp

    for nums, x, t in test_cases:
        max_weight = 0
        nums_with_max_weight = []
        for n in nums:
            weight = max_exponent_dict[n]
            if weight > max_weight:
                max_weight = weight
                nums_with_max_weight = [n]
            elif weight == max_weight:
                nums_with_max_weight.append(n)
        nums_with_max_weight.sort()
        print(' '.join(map(str, nums_with_max_weight)))

if __name__ == "__main__":
    threading.Thread(target=main).start()
