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
    ll n, k; cin >> n >> k;
    vl a(n);
    FOR(i, n) cin >> a[i];
    ll tot = accumulate(ALL(a), 0ll);
    if (tot <= k) {
        cout << 0 << endl;
        return;
    }
    ll ans = tot - k;
    sort(ALL(a));
    //FORR(x, a) cout << x << " "; cout << endl;
    vl suff(n+1);
    REPR(i, n-1, 0) suff[i] = suff[i+1] + a[i] - a[0];
    FOR(sz, n) {
        int i = n-sz;
        ll cost = sz;
        ll cur = (tot - suff[i]) - k;
        if (cur > 0) cost += ceil(cur / (float)(sz+1));
        //cout << sz << ": " << cost << " " << cur <<  endl;
        ans = min(ans, cost);
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
