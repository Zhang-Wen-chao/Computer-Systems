def count_replaces(s):
    def backtrack(index):
        if index == len(s):
            nonlocal count
            count += 1
            return

        if s[index] == '?':
            for char in '012':
                if s[index] == 0 or s[index-1] != char:
                    s[index] = char
                    backtrack(index + 1)
                    s[index] = '?'

        else:
            if index == 0 or s[index-1] != s[index]:
                backtrack(index + 1)


    count = 0
    s = list(s)
    backtrack(0)
    return count

def main():
    s = '?0' # 2
    # s = '??' # 6
    # s = '?0??????2??201???' # 1376
    result = count_replaces(s)
    print(result)


if __name__ == '__main__':
    main()