#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    ans += a;
    if (b % 3 != 0)
        c -= (b % 3 == 1) ? 2 : 1;

    if (c < 0) {
        cout << "-1\n";
        return;
    }

    ans += ceil(b / 3.0);
    ans += ceil(c / 3.0);

    cout << ans << "\n";
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
