#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    FOR(i, n) cin >> a[i + 1];
    vector<pll> dp(n + 1);
    vector<pll> dpc(n + 1);
    dp[1] = {max(a[1], abs(a[1])), min(a[1], abs(a[1]))};

    if (a[1] > 0)
        dpc[1] = {2, 2};
    else
        dpc[1] = {1, 1};

    for (int i = 2; i <= n; i++) {
        dp[i].first = max(abs(dp[i - 1].first + a[i]), abs(dp[i - 1].second + a[i]));
        dp[i].second = min(dp[i - 1].first + a[i], dp[i - 1].second + a[i]);

        if (dp[i].first == dp[i - 1].first + a[i])
            dpc[i].first = (dpc[i].first % MOD + dpc[i - 1].first % MOD) % MOD;

        if (dp[i].first == abs(dp[i - 1].first + a[i]))
            dpc[i].first = (dpc[i].first % MOD + dpc[i - 1].first % MOD) % MOD;

        if (dp[i].second == dp[i - 1].first + a[i])
            dpc[i].second = (dpc[i].second % MOD + dpc[i - 1].first % MOD) % MOD;

        if (dp[i].second == abs(dp[i - 1].first + a[i]))
            dpc[i].second = (dpc[i].second % MOD + dpc[i - 1].first % MOD) % MOD;

        if (dp[i - 1].first != dp[i - 1].second) {
            if (dp[i].first == dp[i - 1].second + a[i])
                dpc[i].first = (dpc[i].first % MOD + dpc[i - 1].second % MOD) % MOD;
            if (dp[i].first == abs(dp[i - 1].second + a[i]))
                dpc[i].first = (dpc[i].first % MOD + dpc[i - 1].second % MOD) % MOD;

            if (dp[i].second == dp[i - 1].second + a[i])
                dpc[i].second = (dpc[i].second % MOD + dpc[i - 1].second % MOD) % MOD;
            if (dp[i].second == abs(dp[i - 1].second + a[i]))
                dpc[i].second = (dpc[i].second % MOD + dpc[i - 1].second % MOD) % MOD;
        }

        dpc[i].first = dpc[i].first % MOD;
        dpc[i].second = dpc[i].second % MOD;
    }

    cout << dpc[n].first << endl;
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

