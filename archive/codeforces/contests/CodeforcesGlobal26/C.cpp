#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    FORR(i, a) cin >> i;
    vector<pll> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        dp[i + 1].first = max(abs(dp[i].first + a[i]), abs(dp[i].second + a[i]));
        dp[i + 1].second = min(dp[i].first + a[i], dp[i].second + a[i]);
    }

    cout << max(dp[n].first, abs(dp[n].second)) << endl;
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

