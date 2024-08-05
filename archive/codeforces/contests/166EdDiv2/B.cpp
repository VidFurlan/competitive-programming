#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n + 1);
    FORR(i, a) cin >> i;
    FORR(i, b) cin >> i;

    ll ans = 0;
    bool f = 0;
    ll dist = INT_MAX;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
        dist = min(dist, abs(b.back() - a[i]));
        if (!f && min(a[i], b[i]) <= b.back() && b.back() <= max(a[i], b[i])) {
            f = 1;
            ans++;
        }
    }

    if (!f) {
        for (int i = 0; i < n; i++)
            dist = min(dist, abs(b.back() - b[i]));
        ans += dist + 1;
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
