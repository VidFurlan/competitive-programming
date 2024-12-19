#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
    ll n, c; cin >> n >> c;
    vector<pll> a(n);
    FORR2(x, y, a) cin >> x >> y;
    ll ans = accumulate(ALL(a), 0LL, [](ll acc, pii p) { return acc + p.fi; });
    vl diff(n);
    FOR(i, n) diff[i] = a[i].fi - a[i].se;
    sort(RALL(diff));
    int need = 0;
    FOR(i, n) {
        if (ans <= c) break;
        ans -= diff[i];
        need++;
    }
    if (ans > c) cout << -1 << endl;
    else cout << need << endl;
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
