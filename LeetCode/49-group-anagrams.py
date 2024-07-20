from typing import List
from collections import defaultdict

def group_anagrams(strs: List[str]) -> List[List[str]]:
    anagrams = defaultdict(list)
    
    for word in strs:
        # Sort the word to use as the key
        sorted_word = ''.join(sorted(word))
        print('sorted_word:', sorted_word)
        # Append the original word to the list of its sorted version
        anagrams[sorted_word].append(word)
        print('anagrams:', anagrams[sorted_word])
        print('*' * 10)
    
    # Return the values of the dictionary as a list of lists
    return list(anagrams.values())

# Example usage:
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(group_anagrams(strs))
