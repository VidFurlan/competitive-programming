#include <bits/stdc++.h>
#include <functional>
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

void solve() {
    int n, q; cin >> n >> q;
    vi a(n), p(n);
    REP(i, 1, n - 1) {
        cin >> a[i];
        a[i]--;
    }
    FORR(x, p) { 
        cin >> x;
        x--;
    }

    vi g(n), par(n, -1), next(n, -1);
    vector<pii> ch(n, {-1, -1});
    int inx = 0;
    function<void(int)> dfs = [&] (int sz) {
        int v = inx++;
        if (sz == 1) return;
        int c1 = inx;
        sz--;
        dfs(sz / 2);
        int c2 = inx;
        dfs(sz / 2);
        next[c1] = c2;
        next[c2] = c1;
        par[c1] = v;
        par[c2] = v;
        ch[v] = {c1, c2};
    };
    dfs(n);

    int cnt = 0;
    auto check = [&] (int i) {
        if (i == -1) return;
        cnt -= g[i];
        g[i] = 0;
        if (i) {
            if (p[par[i]] == a[p[i]])
                g[i] = 1;
        }
        else 
            g[i] = (p[i] == 0 ? 1 : 0);
        cnt += g[i];
    };
    FOR(i, n) check(i);

    auto recheck = [&] (int i) {
        check(i);
        check(ch[i].fi);
        check(ch[i].se);
    };

    while (q--) {
        int u, v; cin >> u >> v;
        u--; v--;
        swap(p[u], p[v]);
        recheck(u);
        recheck(v);
        if (cnt == n) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
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
