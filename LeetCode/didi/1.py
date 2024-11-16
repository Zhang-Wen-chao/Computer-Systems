import sys
import math

def main():
    import threading
    def solve():
        n, m = map(int, sys.stdin.readline().split())
        owned_ids = list(map(int, sys.stdin.readline().split()))
        owned_ids.sort()
        total_cost = 0
        toys_bought = 0
        previous_owned_id = 0
        max_id = m  # The maximum ID we need to consider is m because IDs beyond m are too expensive.

        for owned_id in owned_ids:
            start = previous_owned_id + 1
            end = owned_id - 1
            if start > end:
                previous_owned_id = owned_id
                continue
            sum_interval = (start + end) * (end - start + 1) // 2
            if total_cost + sum_interval <= m:
                total_cost += sum_interval
                toys_bought += (end - start + 1)
            else:
                # Need to compute maximum k
                S = m - total_cost
                a = 1
                b = 2 * start - 1
                c = -2 * S
                D = b * b - 4 * a * c
                if D < 0:
                    k = 0
                else:
                    sqrt_D = int(math.isqrt(D))
                    k = (-b + sqrt_D) // (2 * a)
                    # Ensure k is within the interval
                    k = min(k, end - start +1)
                    if k < 0:
                        k = 0
                sum_k = k * (2 * start + k - 1) // 2
                total_cost += sum_k
                toys_bought += k
                # Cannot buy more toys
                print(toys_bought)
                return
            previous_owned_id = owned_id

        # Process the last interval
        start = previous_owned_id +1
        end = min(max_id, 1_000_000_000)
        if start <= end:
            sum_interval = (start + end) * (end - start + 1) // 2
            if total_cost + sum_interval <= m:
                total_cost += sum_interval
                toys_bought += (end - start + 1)
            else:
                S = m - total_cost
                a =1
                b = 2*start -1
                c = -2*S
                D = b*b - 4*a*c
                if D <0:
                    k=0
                else:
                    sqrt_D = int(math.isqrt(D))
                    k = (-b + sqrt_D) // (2 * a)
                    k = min(k, end - start +1)
                    if k < 0:
                        k =0
                sum_k = k*(2*start + k -1)//2
                total_cost += sum_k
                toys_bought += k
        print(toys_bought)
    threading.Thread(target=solve).start()
    
if __name__ == "__main__":
    main()
