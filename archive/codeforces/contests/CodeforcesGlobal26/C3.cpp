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
    vector<ll> dp1(n + 1), dp2(n + 1);
    vector<ll> dpc1(n + 1), dpc2(n + 1);
    dp1[1] = max(a[1], abs(a[1]));
    dp2[1] = min(a[1], abs(a[1]));
    if (a[1] > 0) {
        dpc1[1] = 2;
        dpc2[1] = 2;
    } 
    else {
        dpc1[1] = 1;
        dpc2[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp1[i] = max({
                dp1[i - 1] + a[i],
                abs(dp1[i - 1] + a[i]),
                dp2[i - 1] + a[i],
                abs(dp2[i - 1] + a[i])
                });

        if (dp1[i] == dp1[i - 1] + a[i])
            dpc1[i] = (dpc1[i] + dpc1[i - 1]) % MOD;

        if (dp1[i] == abs(dp1[i - 1] + a[i]))
            dpc1[i] = (dpc1[i] + dpc1[i - 1]) % MOD;

        if (dp1[i - 1] != dp2[i - 1]) {
            if (dp1[i] == dp2[i - 1] + a[i])
                dpc1[i] = (dpc1[i] + dpc2[i - 1]) % MOD;

            if (dp1[i] == abs(dp2[i - 1] + a[i]))
                dpc1[i] = (dpc1[i] + dpc2[i - 1]) % MOD;
        }

        dp2[i] = min({
                dp1[i - 1] + a[i],
                abs(dp1[i - 1] + a[i]),
                dp2[i - 1] + a[i],
                abs(dp2[i - 1] + a[i])
                });

        if (dp2[i] == dp1[i - 1] + a[i])
            dpc2[i] = (dpc2[i] + dpc1[i - 1]) % MOD;

        if (dp2[i] == abs(dp1[i - 1] + a[i]))
            dpc2[i] = (dpc2[i] + dpc1[i - 1]) % MOD;

        if (dp1[i - 1] != dp2[i - 1]) {
            if (dp2[i] == dp2[i - 1] + a[i])
                dpc2[i] = (dpc2[i] + dpc2[i - 1]) % MOD;

            if (dp2[i] == abs(dp2[i - 1] + a[i]))
                dpc2[i] = (dpc2[i] + dpc2[i - 1]) % MOD;
        }
    }

    cout << dpc1[n] << endl;
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

