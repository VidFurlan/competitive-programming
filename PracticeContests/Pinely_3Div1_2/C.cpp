#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<ll> l(n), r(n), c(n);

    for (ll &i : l) cin >> i;
    for (ll &i : r) cin >> i;
    for (ll &i : c) cin >> i;

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    sort(c.begin(), c.end(), greater<ll>());

    ll ans = 0;
    for (int i = 0; i < n; i++) 
        ans += (r[i] - l[i]) * c[i];
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
