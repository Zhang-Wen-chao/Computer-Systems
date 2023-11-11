def letterCombinations(digits):
    if not digits:
        return []

    phone_map = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz"
    }

    def backtrack(index, path):
        if index == len(digits):
            combinations.append("".join(path))
            return

        possible_letters = phone_map[digits[index]]
        for letter in possible_letters:
            path.append(letter)
            backtrack(index + 1, path)
            path.pop()

    combinations = []
    backtrack(0, [])
    return combinations

# Test cases
print(letterCombinations("23"))  # Example: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
print(letterCombinations(""))    # Should return an empty list
print(letterCombinations("2"))   # Should return ["a", "b", "c"]
