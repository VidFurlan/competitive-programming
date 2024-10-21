#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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
    int n; cin >> n;
    vvi adj(n);
    FOR(i, n-1) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi dep(n);
    vi mx(n);
    vi psum(n);

    function<void(int, int)> dfs = [&](int p, int x) {
        mx[x] = dep[x];
        FORR(y, adj[x]) {
            if (y == p) continue;
            dep[y] = dep[x] + 1;
            dfs(x, y);
            mx[x] = max(mx[x], mx[y]);
        }
        psum[0]++;
        psum[dep[x]]--;
        if (mx[x] + 1 < n) {
            psum[mx[x] + 1]++;
        }
    };

    dfs(-1, 0);
    REP(i, 1, n-1) psum[i] += psum[i-1];

    // debug(mx);
    // FORR(x, low) cout << x << " ";
    // cout << endl;
    // FORR(x, upper) cout << x << " ";
    // cout << endl;

    int ans = *min_element(ALL(psum));
    cout << ans << endl;
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
