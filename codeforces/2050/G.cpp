#include <bits/stdc++.h>
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

vector<set<int>> adj;
int ans;

int dfs(int u, int p) {
    int mx1 = 0, mx2 = 0;
    FORR(v, adj[u]) {
        if (v == p) continue;
        int add = dfs(v, u);
        if (add > mx1) {
            mx2 = mx1;
            mx1 = add;
        }
        else {
            mx2 = max(mx2, add);
        }
    }
    ans = max(ans, mx1 + mx2 + SZ(adj[u]) - 2);
    return mx1 + SZ(adj[u]) - 2;
}

void solve() {
    int n; cin >> n;
    adj = vector<set<int>>(n);
    FOR(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    if (n <= 2) {
        cout << 1 << endl;
        return;
    }

    vi l;
    FOR(i, n) {
        if (SZ(adj[i]) == 1) {
            l.push_back(i);
        }
    }

    ans = 0;
    dfs(0, -1);
    cout << ans + 2 << endl;
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
