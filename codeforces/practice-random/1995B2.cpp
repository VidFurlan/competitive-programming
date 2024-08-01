#include <bits/stdc++.h>
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
    ll n, m; cin >> n >> m;
    vector<pll> b(n);
    FORR(x, b) cin >> x.first;
    FORR(x, b) cin >> x.second;
    sort(ALL(b));

    ll ans = 0;
    for (ll i = 0; i < b.size(); i++) {
        pll cur = b[i];
        pll next = {b[i].first + 1, 0};
        if (i + 1 < b.size() && b[i + 1].first == b[i].first + 1) next = b[i + 1];

        ll x = min(cur.second, m / cur.first);
        ll y = min(next.second, (m - x * cur.first) / (cur.first + 1));
        ans = max(ans, x * cur.first + y * (cur.first + 1) + min({x, next.second - y, (m - x * cur.first) % (cur.first + 1)}));
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
