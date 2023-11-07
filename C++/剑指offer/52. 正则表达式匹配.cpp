#include <iostream>
#include <string>

using namespace std;

bool isMatch(const string& s, const string& p) {
    if (p.empty()) return s.empty();

    // First match makes sure that the characters actually match or there's a '.'
    bool first_match = (!s.empty() &&
                        (p[0] == s[0] || p[0] == '.'));

    if (p.length() >= 2 && p[1] == '*') {
        // If the pattern has a star, we could either ignore the star part
        // or delete a matching character in the string
        return (isMatch(s, p.substr(2)) ||
                (first_match && isMatch(s.substr(1), p)));
    } else {
        return first_match && isMatch(s.substr(1), p.substr(1));
    }
}

int main() {
    string s, p;
    cout << "Enter the string to match: ";
    cin >> s;
    cout << "Enter the pattern: ";
    cin >> p;

    if (isMatch(s, p)) {
        cout << "The string matches the pattern." << endl;
    } else {
        cout << "The string does not match the pattern." << endl;
    }

    return 0;
}
