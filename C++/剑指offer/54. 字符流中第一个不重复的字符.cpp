#include <iostream>
#include <vector>
#include <climits> // Include for INT_MAX

using namespace std;

class CharStatistics {
public:
    CharStatistics() : occurrence(256, -1), index(0) {}

    void Insert(char ch) {
        if (occurrence[ch] == -1) {
            occurrence[ch] = index; // First time occurrence
        } else if (occurrence[ch] >= 0) {
            occurrence[ch] = -2; // Repeated occurrence
        }
        index++;
    }

    char FirstAppearingOnce() {
        char ch = '\0';
        int minIndex = INT_MAX;
        for (int i = 0; i < 256; ++i) {
            if (occurrence[i] >= 0 && occurrence[i] < minIndex) {
                ch = (char)i;
                minIndex = occurrence[i];
            }
        }
        if (minIndex == INT_MAX) return '#'; // No unique char
        return ch;
    }

private:
    vector<int> occurrence; // Occurrence index, -1 for not appeared, -2 for repeated
    int index; // Current index
};

int main() {
    CharStatistics stats;
    // Simulate the character stream
    stats.Insert('g');
    stats.Insert('o');
    stats.Insert('o');
    stats.Insert('g');
    stats.Insert('l');
    stats.Insert('e');

    cout << "The first non-repeating character is: " << stats.FirstAppearingOnce() << endl;

    return 0;
}
