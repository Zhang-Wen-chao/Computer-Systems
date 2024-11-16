n, m = map(int, input().split())
n = int(n)
m = int(m)

ai = []
for _ in range(n):
    ai_i = list(map(int, input().split()))
    ai.append(ai_i)

# Compute total_likes for each dish
total_likes = []
for j in range(m):
    total = sum(ai[i][j] for i in range(n))
    total_likes.append((total, j))

# Sort dishes based on total_likes in decreasing order
total_likes.sort(reverse=True)

# Xiaoxing picks the top 3 dishes
dishes_picked_by_xiaoxing = [j for total, j in total_likes[:3]]
ordered_dishes = set(dishes_picked_by_xiaoxing)

# Each other person picks their most liked dish not yet ordered
for i in range(1, n):
    # Create a list of (like, dish_index) for dishes not yet ordered
    ai_i_with_dishes = [(ai[i][j], j) for j in range(m) if j not in ordered_dishes]
    # Sort in decreasing order of likes
    ai_i_with_dishes.sort(reverse=True)
    if ai_i_with_dishes:
        # Person picks their most liked dish not yet ordered
        best_dish = ai_i_with_dishes[0][1]
        ordered_dishes.add(best_dish)

# Calculate total likes for each person
total_sum = 0
for i in range(n):
    person_total = sum(ai[i][j] for j in ordered_dishes)
    total_sum += person_total

print(total_sum)
