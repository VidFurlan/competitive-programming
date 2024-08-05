#include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;
const ll LINF = 0x1fffffffffffffff;
int m, x, ans;

void solve() {
    ll m, x, mh = 0;
    cin >> m >> x;

    vector<ll> c(m), h(m);
    for (ll i = 0; i < m; i++) {
        cin >> c[i] >> h[i];
        mh += h[i];
    }

    vector<ll> dp(mh + 1, -LINF);
    dp[0] = 0;
    for (ll i = 0; i < m; i++) {
        for (int j = mh; j >= h[i]; j--)
            if (dp[j - h[i]] >= c[i])
                dp[j] = max(dp[j], dp[j - h[i]] - c[i]);
        for (ll &j : dp)
            j += x;
    }

    // for (int i = 0; i <= mh + 1; i++)
    //     cout << max(dp[i], (ll)-1) << " ";
    // cout << endl;

    for (ll i = mh; i >= 0; i--)
        if (dp[i] >= 0) {
            cout << i << endl;
            return;
        }
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
