#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;

    sort(a.begin(), a.end());

    // for (pii p : a) 
    //     cout << p.first << " " << p.second << ",  ";
    // cout << endl;

    ll ans = 0, extra = 0;
    for (int i = 0; i < n && k > 0; i++) {
            ans += min(m, k) * (a[i] + extra);
            k -= m;
            extra += m;

        // cout << "p: " << p.first << "   a: " << ans << "   e: " << extra << endl;
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
