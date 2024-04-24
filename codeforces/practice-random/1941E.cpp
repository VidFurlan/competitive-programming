#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    ll n, m, k, d; 
    cin >> n >> m >> k >> d;

    vector<vector<int>> grid(n, vector<int>(m));
    for (vector<int> &r : grid) 
        for (int &c : r)
            cin >> c;
    
    vector<vector<ll>> dp(n, vector<ll>(m, LONG_LONG_MAX));
    vector<ll> a(n);

    for (int r = 0; r < n; r++) {
        multiset<ll> s = {1};
        dp[r][0] = 1;

        for (int i = 1; i < m; i++) {
            dp[r][i] = *s.begin() + grid[r][i] + 1;
            if (i - d - 1 >= 0) 
                s.erase(s.find(dp[r][i - d - 1]));
            s.insert(dp[r][i]);
        }

        /*cout << "\n" << r << " -> ";
        for (int c : dp[r])
            cout << c << " ";*/
        a[r] = dp[r].back();
    }

    ll cur = 0;
    for (int i = 0; i < k; i++) 
        cur += a[i];

    ll ans = cur;
    for (int i = k; i < n; i++) {
        cur += a[i] - a[i - k];
        ans = min(ans, cur);
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
