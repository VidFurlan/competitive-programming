#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, m;
        string s;
        cin >> n >> k >> m >> s;
        unordered_map<char, int> map;
        for (char ch : s) 
            map[ch]++;
        
        string ans;
        bool invalid = false;

        for (int i = 0; i < k; i++) {
            if (map['a' + i] < n) {
                invalid = true;

                for (int j = 0; j < n; j++)
                    ans += ('a' + i);
                
                break;
            }
        }

        if (invalid)
            cout << "NO\n" << ans << '\n';
        else
            cout << "YES\n";
    }
}
