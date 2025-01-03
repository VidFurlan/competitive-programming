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

void solve() {
    int n; cin >> n;
    vi a(n);
    FOR(i, n) cin >> a[i];
    vi d(n);
    d[0] = 1, d[n-1] = -1;
    REP(i, 1, n-2) d[i] = (a[i] - a[i-1] < a[i+1] - a[i]) ? -1 : 1;
    //FORR(x, d) cout << x << " "; cout << endl;
    vi pref(n);
    REP(i, 1, n-1) {
        if (d[i-1] == 1) pref[i] = pref[i-1] + 1;
        else pref[i] = pref[i-1] + a[i] - a[i-1];
    }
    //FORR(x, pref) cout << x << " "; cout << endl;
    vi suff(n);
    REPR(i, n-2, 0) {
        if (d[i+1] == -1) suff[i] = suff[i+1] + 1;
        else suff[i] = suff[i+1] + a[i+1] - a[i];
    }
    //FORR(x, suff) cout << x << " "; cout << endl;

    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        x--, y--;
        cout << (x < y ? pref[y] - pref[x] : suff[y] - suff[x]) << endl;
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
