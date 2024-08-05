#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    FORR(x, a) cin >> x;
    sort(ALL(a));

    FOR(i, n-1) {
        if (a[i] + k > a.back()) continue;
        ll x = a.back() - a[i] - k;
        x = (x + 2 * k - 1) / (2 * k);
        a[i] += x * 2 * k;
    }

    sort(ALL(a));
    FOR(i, n) a.push_back(a[i] + 2 * k);
    ll ans = LLONG_MAX;
    for (int i = n - 1; i < 2 * n; i++) {
        if (a[i] - a[i - n + 1] >= k) continue;
        ans = min(ans, a[i]);
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
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
