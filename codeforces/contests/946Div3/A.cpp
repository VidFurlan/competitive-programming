#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int x, y; cin >> x >> y;
    int ans = ceil(y / 2.0);
    int total = 15 * ans - 4 * y;
    // cout << "f: " << total << "  ans ";
    if (total < x) {
        x -= total;
        ans += ceil(x / 15.0);
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
