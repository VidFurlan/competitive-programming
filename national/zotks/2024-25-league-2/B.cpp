#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define SINGLE_TEST 1

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
    vvi g(n+1);

    REP(i, 1, n) {
        string line;
        getline(cin >> ws, line);
        stringstream ss(line);
        int u, v;
        if (ss >> u) {
            if (u == 0) continue;
            if (ss >> v) {
                g[i].push_back(v);
                g[i].push_back(u);
            }
        }
    }

    int m; cin >> m;
    //FOR(i, n+1) {
    //    cout << i << ": ";
    //    FORR(x, g[i]) cout << x << " ";
    //    cout << endl;
    //}
    int ans = 0;
    vi dp(n+1, -1);
    dp[m] = 1;
    auto dfs = [&](int u, auto dfs) -> int {
        if (SZ(g[u]) == 0 && u != m) return dp[u] = 0;
        if (dp[u] != -1) return dp[u];
        int tot = dfs(g[u][0], dfs) + dfs(g[u][1], dfs);
        if (tot == 2) ans++;
        if (tot >= 1) dp[u] = 1;
        else dp[u] = 0;
        // cout << u << " " << dp[u] << " " << tot << endl;
        return dp[u];
    };

    REP(i, 1, n) {
        if (i == m) continue;
        if (dp[i] == -1) {
            dfs(i, dfs);
        }
    }

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
