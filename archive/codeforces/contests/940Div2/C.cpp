#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    ll n, k; cin >> n >> k;
    ll new_n = n;
    for (ll i = 0; i < k; i++) {
        ll c, r;
        cin >> c >> r;
        if (c == r)
            new_n -= 1;
        else 
            new_n -= 2;
    }

    vector<ll> dp(new_n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (ll i = 2; i <= new_n; i++) {
        dp[i] = (2 * (i - 1) * dp[i - 2] + dp[i - 1]) % (ll)(1e9 + 7);
        cout << '\t' << i << " -> " << dp[i] << '\n';
    }

    cout << dp[new_n] << '\n';
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
