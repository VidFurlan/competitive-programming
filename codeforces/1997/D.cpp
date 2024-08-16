#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define SINGLE_TEST 0

typedef long long ll;
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
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

ll dfs(ll v, vector<set<ll>> &g, vl &a) {
    if (g[v].empty()) return a[v];
    ll mn = LLINF;
    FORR(u, g[v]) {
        mn = min(mn, dfs(u, g, a));
    }
    if (v == 0) return mn + a[v];
    if (mn < a[v]) return mn;
    return (mn - a[v]) / 2 + a[v];
}

void solve() {
    ll n; cin >> n;
    vl a(n);
    FORR(x, a) cin >> x;
    vector<set<ll>> g(n);
    FOR(i, n - 1) {
        ll p; cin >> p;
        p--;
        g[p].insert(i + 1);
    }

    cout << dfs(0, g, a) << endl;
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
