import sys
import threading
import bisect

def main():
    def solve():
        import sys

        sys.setrecursionlimit(1 << 25)
        n = int(sys.stdin.readline())
        xi_vi = []
        for _ in range(n):
            xi, vi = map(int, sys.stdin.readline().split())
            xi_vi.append((xi, vi))

        # Sort cars by their positions xi
        xi_vi.sort()

        # Extract the velocities vi
        vi_list = [vi for xi, vi in xi_vi]

        # Find the length of the Longest Non-Decreasing Subsequence (LNDS)
        ends = []

        for vi in vi_list:
            # Use bisect_right to find the insertion point
            index = bisect.bisect_right(ends, vi)
            if index == len(ends):
                ends.append(vi)
            else:
                ends[index] = vi

        min_cars_to_remove = n - len(ends)
        print(min_cars_to_remove)

    threading.Thread(target=solve).start()

if __name__ == "__main__":
    main()
