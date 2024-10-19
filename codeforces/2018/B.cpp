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
    int n; cin >> n;
    vi a(n);
    vector<pii> b(n + 1, {INF, -INF});
    FOR(i, n) {
        cin >> a[i];
        b[a[i]] = {min(b[a[i]].fi, i), max(b[a[i]].se, i)};
    }
    pii cur = {INF, -INF};
    REP(j, 1, n) {
        if (b[j].fi == INF) continue;
        cur.fi = min(cur.fi, b[j].fi);
        cur.se = max(cur.se, b[j].se);
        int span = cur.se - cur.fi + 1;
        if (span > j) {
            cout << 0 << endl;
            return;
        }

        int slack = j - span;
        b[j].fi = max(cur.fi - slack, 0);
        b[j].se = min(cur.se + slack, n - 1);
    }

    //FORR2(x, y, b) {
    //    cout << x << " " << y << endl;
    //}

    pii ans = {0, n - 1};
    REPR(j, n - 1, 0) {
        if (b[j].fi == INF) continue;
        ans.fi = max(ans.fi, b[j].fi);
        ans.se = min(ans.se, b[j].se);
    }

    cout << ans.se - ans.fi + 1 << endl;
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
