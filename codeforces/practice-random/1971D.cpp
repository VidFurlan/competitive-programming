#include <bits/stdc++.h>
#include <string>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    string s; cin >> s;
    int ans = 1;
    for (int i = 1; i < s.size(); i++)
        if (s[i] != s[i - 1])
            ans++;

    for (int i = 1; i < s.size(); i++)
        if (s[i] == '1' && s[i - 1] == '0') {
            ans--;
            break;
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
