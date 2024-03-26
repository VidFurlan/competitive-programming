#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, m;
        string s;
        cin >> n >> k >> m >> s;

        vector<int> charPositions[26]; // Array to store positions of each character
        for (int i = 0; i < m; ++i) {
            charPositions[s[i] - 'a'].push_back(i);
        }

        string invalidString;
        int idx = m - 1; // Start from the end of the string
        for (int i = n - 1; i >= 0; --i) {
            int ch = 'a' + i;
            if (charPositions[ch - 'a'].empty()) {
                invalidString += ch;
            } else {
                // Find the position of the character in s that is just before the current index
                auto it = upper_bound(charPositions[ch - 'a'].begin(), charPositions[ch - 'a'].end(), idx);
                if (it == charPositions[ch - 'a'].begin()) {
                    invalidString += ch;
                } else {
                    idx = *(--it);
                }
            }
        }

        if (invalidString.length() == n) {
            cout << "NO\n" << invalidString << "\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
