#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    string s; cin >> s;
    ll ans = 0;
    ll ones = 0, i = 0;
    while (i < s.size() && s[i] == '0') i++;
    while (i < s.size()) {
        if (s[i] == '1') {
            ones++; i++;
            continue;
        }

        ans += ones + 1;
        i++;
    }       
    cout << ans << endl;
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
