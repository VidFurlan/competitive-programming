#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    for (int sh = 0; sh < n; sh++) {
        ll m = LL_INF;
        for (int i = 0; i < n; i++)
            m = min(m, (ll)abs(a[i] - b[(i + sh) % n]));
        ans = max(ans, m);
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
