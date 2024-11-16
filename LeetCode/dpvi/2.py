MOD = 10**9 + 7

n_str, m_str = input().split()
n = int(n_str)
m = int(m_str)

n1 = n - 1
m1 = m - 1
exponent = n * m - 3
pow2 = pow(2, exponent, MOD)
ans = (n1 * m1) % MOD
ans = (ans * pow2) % MOD

print(ans)
