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
    vi a(2), b(2);
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    vector<pair<pii, pii>> pos = {
        {{a[0], b[0]}, {a[1], b[1]}},
        {{a[0], b[1]}, {a[1], b[0]}},
        {{a[1], b[0]}, {a[0], b[1]}},
        {{a[1], b[1]}, {a[0], b[0]}}
    };

    int ans = 0;
    FORR(p, pos) {
        int su = (p.fi.fi > p.fi.se) + (p.se.fi > p.se.se);
        int sl = (p.fi.fi < p.fi.se) + (p.se.fi < p.se.se);

        if (su > sl)
            ans++;
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
