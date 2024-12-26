#include <iostream>
#include <utility>
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
    int n; cin >> n;
    string s; cin >> s;
    vector<pii> adj(n);
    FOR(i, n) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[i] = {u, v};
    }

    int ans = INF;
    auto dfs = [&](int v, int bad, auto dfs) -> void {
        if (v == -1) return;
        if (adj[v] == make_pair(-1, -1)) ans = min(ans, bad);
        if (s[v] == 'U') bad++;
        if (s[v] == 'L') dfs(adj[v].se, bad+1, dfs);
        else dfs(adj[v].se, bad, dfs);
        if (s[v] == 'R') dfs(adj[v].fi, bad+1, dfs);
        else dfs(adj[v].fi, bad, dfs);
    };
    dfs(0, 0, dfs);
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
