def calculate_attempts(n, correct_password, password_list):
    password_list = list(set(password_list))
    password_list.sort(key=len)
    min_attempts = 0
    max_attempts = 0
    same_length_count = 0
    total_attempts = 0

    for password in password_list:
        if len(password) < len(correct_password):
            total_attempts += 1
        if len(password) == len(correct_password):
            same_length_count += 1

        min_attempts = total_attempts + 1
        max_attempts = total_attempts + same_length_count
    return min_attempts, max_attempts

n = int(input())
correct_password = input().strip()
password_list = [input().strip() for _ in range(n)]

min_attempts, max_attempts = calculate_attempts(n, correct_password, password_list)
print(min_attempts, max_attempts)