#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (unsigned int i = 0; i < board.size(); i++) {
            for (unsigned int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int wordIndex) {
        if (wordIndex == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[wordIndex]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#'; // Mark as visited
        bool found = backtrack(board, word, i + 1, j, wordIndex + 1)
                  || backtrack(board, word, i - 1, j, wordIndex + 1)
                  || backtrack(board, word, i, j + 1, wordIndex + 1)
                  || backtrack(board, word, i, j - 1, wordIndex + 1);
        board[i][j] = temp; // Unmark
        return found;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    Solution solution;
    bool exists = solution.exist(board, word);
    cout << "Does the path exist? " << (exists ? "Yes" : "No") << endl;
    return 0;
}
