
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 1; i <= n; i++) {
        if (n % i != 0)
            continue;

        string s1, s2;
        while (s1.size() < s.size())
            s1 += s.substr(0, i);
        while (s2.size() < s.size())
            s2 += s.substr(s.size() - i, i);

        int diff1 = 0, diff2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != s1[i])
                diff1++;
            if (s[i] != s2[i])
                diff2++;
        }

        // cout << s1 << endl << s2 << endl;
        if (diff1 <= 1 || diff2 <= 1) {
            cout << i << "\n";
            return;
        }
    }

    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
