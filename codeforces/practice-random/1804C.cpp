#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    ll n, x, p;
    cin >> n >> x >> p;

    p = min(p, n * 2);
    if (x != 0)
        x = n - x;
    for (ll f = 1; f <= p; f++) {
        if ((f * (f + 1) / 2) % n == x) {
            cout << "YES\n";
            return;
        }
    }

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
