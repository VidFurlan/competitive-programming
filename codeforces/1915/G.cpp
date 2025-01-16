#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
#define SINGLE_TEST 0

typedef long long ll;
typedef unsigned long long ull; 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define REP(i, k, n) for (int(i) = (k); (i) <= (n); ++(i))
#define REPR(i, k, n) for (int(i) = (k); (i) >= (n); --(i))
#define FORR(x, arr) for (auto &x : arr)
#define FORR2(x, y, arr) for (auto &[x, y] : arr)
#define ALL(a) (a.begin()), (a.end())
#define RALL(a) (a.rbegin()), (a.rend())
#define REVERSE(v) reverse(ALL(v))
#define SZ(x) (int)(x).size()
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << (x) << endl

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pll>> adj(n);
    FOR(i, m) {
        ll u, v, w; cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vl slow(n);
    FOR(i, n) cin >> slow[i];
    vvl dist(n, vl(1001, LLINF));
    priority_queue<vl, vvl, greater<vl>> pq;
    int start = 0;
    dist[start][slow[start]] = 0;
    pq.push({0, slow[start], start});
    while (SZ(pq)) {
        vl top = pq.top(); pq.pop();
        ll d = top[0], s = top[1], u = top[2];
        s = min(s, slow[u]);
        if (d > dist[u][s]) continue;
        FORR2(v, w, adj[u]) {
            ll newD = d + w * s;
            if (newD < dist[v][s]) {
                dist[v][s] = newD;
                pq.push({newD, s, v});
            }
        }
    }
    cout << *min_element(ALL(dist[n - 1])) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#if SINGLE_TEST
    solve();
#else
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
#endif

    return 0;
}
