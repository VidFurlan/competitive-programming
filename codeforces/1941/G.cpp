#include <bits/stdc++.h>
#include <functional>
#include <queue>
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
const int MAXC = 2 * 1e5 + 100;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pll>> adj(n);
    map<ll, ll> mp;
    int idx = n;
    FOR(i, m) {
        int u, v, c; cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        if (!mp.count(c)) {
            mp[c] = idx++;
        }
    }
    ll b, e; cin >> b >> e;
    b--, e--;
    if (b == e) {
        cout << 0 << endl;
        return;
    }
    vector<set<ll>> g(n + SZ(mp));
    FOR(u, n) {
        FORR2(v, c, adj[u]) {
            ll cc = mp[c];
            g[u].insert(cc);
            g[cc].insert(u);
            g[v].insert(cc);
            g[cc].insert(v);
        }
    }
    m = SZ(g);
    vl seen(m), dist(m, LLINF);
    queue<ll> q;
    q.push(b);
    seen[b] = 1;
    dist[b] = 0;
    while (SZ(q)) {
        ll u = q.front(); q.pop();
        FORR(v, g[u]) {
            if (seen[v]) continue;
            q.push(v);
            seen[v] = 1;
            dist[v] = dist[u] + 1;
        }
    }
    //FORR(x, dist) cout << x << " ";
    cout << dist[e] / 2 << endl;
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
