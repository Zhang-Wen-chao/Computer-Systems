import sys

def main():
    import sys
    import threading
    def solve():
        n_k = sys.stdin.readline().split()
        while len(n_k) < 2:
            n_k += sys.stdin.readline().split()
        n, k = map(int, n_k)
        n = int(n)
        k = int(k)
        ai_line = []
        while len(ai_line) < n:
            ai_line += sys.stdin.readline().split()
        ai = list(map(int, ai_line[:n]))

        group_count = 1
        current_max = current_min = ai[0]

        for i in range(1, n):
            current_max = max(current_max, ai[i])
            current_min = min(current_min, ai[i])
            if current_max - current_min > k:
                group_count += 1
                current_max = current_min = ai[i]
        print(group_count)

    threading.Thread(target=solve).start()

if __name__ == "__main__":
    main()
