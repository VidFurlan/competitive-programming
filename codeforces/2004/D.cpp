#include <bits/stdc++.h>
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
    
    vl a(n);
    vvl g(16);
    FOR(i, n) {
        string s; cin >> s;
        FORR(c, s) {
            if (c == 'R') a[i] |= 1;
            if (c == 'G') a[i] |= 2;
            if (c == 'B') a[i] |= 4;
            if (c == 'Y') a[i] |= 8;
        }
    }
    
    FOR(i, n) g[a[i]].push_back(i);

    while (q--) {
        int x, y; cin >> x >> y;
        x--; y--;
        
        if (a[x] & a[y]) {
            cout << abs(x - y) << endl;
            continue;
        }

        ll ans = LLINF;
        FOR(i, 16) {
            if (__builtin_popcount(i) == 2 && (i & a[x]) && (i & a[y])) {
                ll p = distance(g[i].begin(), lower_bound(ALL(g[i]), x));

                REP(j, p - 3, p + 3) {
                    if (!(0 <= j && j < g[i].size())) continue;
                    
                    ll hop = g[i][j];
                    ans = min(ans, abs(hop - x) + abs(hop - y));
                }
            }
        }

        cout << (ans == LLINF ? -1 : ans) << endl;
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
