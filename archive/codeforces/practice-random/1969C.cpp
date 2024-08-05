#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <iomanip>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, LL_INF));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            ll m = LL_INF;
            for (int d = 0; j + d <= k && i + d < n; d++) {
                m = min(m, a[i + d]);
                dp[i + d + 1][j + d] = min(dp[i + d + 1][j + d], dp[i][j] + (d + 1) * m);
            }
        }
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
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
