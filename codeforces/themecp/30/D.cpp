#include <iostream>
#include <vector>
#include <algorithm>
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
    int n, k; cin >> n >> k;
    vi a(n);
    FOR(i, k) {
        int u; cin >> u;
        u--;
        a[u] = 1;
    }
    vvi adj(n);
    FOR(i, n-1) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    int mx = -1, mxV = -1;
    auto dfs = [&](int u, int p, int d, auto dfs) -> void {
        if (a[u] && d > mx) {
            mx = d;
            mxV = u;
        }
        FORR(v, adj[u]) {
            if (v == p) continue;
            dfs(v, u, d+1, dfs);
        }
    };

    dfs(0, -1, 0, dfs);
    int mx1 = mxV;
    mx = -1;
    dfs(mx1, -1, 0, dfs);
    int mx2 = mxV;
    int ans = -1;
    auto dist = [&](int u, int p, int d, auto dist) -> void {
        if (ans != -1) return;
        if (u == mx2) { ans = d; return; }
        FORR(v, adj[u]) {
            if (v == p) continue;
            dist(v, u, d+1, dist);
        }
    };
    dist(mx1, -1, 0, dist);
    cout << (ans + 1) / 2 << endl;
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
