#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, m, cnt = 0;
    string temp, s, ans;
    cin >> n >> k >> m >> temp;

    for (char el : temp) {
        if (k > static_cast<int>(el) - 'a') {
            s.push_back(el);
        }
    }

    if (s.empty()) {
        cout << "NO\n";
        for (int i = 0; i < n; ++i) {
            cout << 'a';
        }
        cout << "\n";
        return;
    }

    map<char, int> mp;

    for (char el : s) {
        mp[el]++;
        if (mp.size() == k) {
            ans.push_back(el);
            ++cnt;
            mp.clear();
        }
    }

    if (cnt >= n) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";

    if (mp.empty()) {
        while (ans.size() < n) {
            ans.push_back(s.back());
        }
        cout << ans << "\n";
        return;
    }

    char g;

    for (char c = 'a'; c < static_cast<char>(97 + k); ++c) {
        if (mp[c] == 0) {
            g = c;
            break;
        }
    }

    while (ans.size() < n) {
        ans.push_back(g);
    }

    cout << ans << "\n";
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
