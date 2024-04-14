#include <bits/stdc++.h>
#include <string>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int on = 0;
    for (char ch : s)
        on += ch - '0';

    bool valid = true;
    if (on == 2) {
        for (int i = 1; i < n; i++)
            if (s[i] == '1' && s[i-1] == '1') {
                valid = false;
                break;
            }
    }
    if (on % 2 == 1)
        valid = false;

    if (valid == true) 
        cout << "YES\n";
    else 
        cout << "NO\n";
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
