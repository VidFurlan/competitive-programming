#include <bits/stdc++.h>
#include <functional>
#include <queue>
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
    ll h, n; cin >> h >> n;
    vector<pll> a(n);
    FORR(i, a) cin >> i.first;
    FORR(i, a) cin >> i.second;
    ll ans = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    FOR(i, n) pq.push({1, i});

    while (h > 0) {
        ans = pq.top().first;

        while (pq.size() && pq.top().first == ans) {
            pll t = pq.top();
            pq.pop();
            h -= a[t.second].first;
            pq.push({ans + a[t.second].second, t.second});
        }
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
