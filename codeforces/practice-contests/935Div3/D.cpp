#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(n);
    for (ll &i : a) cin >> i;
    for (ll &i : b) cin >> i;

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][0] = min(dp[i+1][0], dp[i+1][1]) + a[i];
        dp[i][1] = min(dp[i+1][0], dp[i+1][1]) + b[i];
    }

    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < m; i++) {
        ans = min(ans, dp[i][0]);
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
