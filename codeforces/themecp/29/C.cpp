#include <algorithm>
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

ll trig(ll n) {
    return n * (n + 1) / 2;
}

void solve() {
    int n; cin >> n;
    vl a(n);
    FOR(i, n) cin >> a[i];
    vl pref(n+1);
    FOR(i, n) pref[i+1] = pref[i] + a[i];
    //FORR(x, pref) cout << x << " "; cout << endl;
    int q; cin >> q;
    while (q--) {
        ll l, u; cin >> l >> u;
        l--;
        ll pos1 = lower_bound(ALL(pref), pref[l] + u) - pref.begin() - 1;
        ll pos2 = pos1-1;
        ll ans = -LLINF, idx = -1;
        if (pos1 < n) {
            ll sz = pref[pos1+1] - pref[l];
            ans = u * sz - trig(sz - 1);
            idx = pos1;
            //cout << "p1(" << ans << " " << pos1 << ")\n";
        }
        if (pos2 >= l) {
            ll sz = pref[pos2+1] - pref[l];
            ll ans2 = u * sz - trig(sz - 1);
            if (ans2 >= ans) idx = pos2;
            //cout << "p2(" << ans2 << " " << pos2 << ")->";
            //cout << idx << " ";
        }
        cout << idx+1 << " ";
        //cout << endl;
    }
    cout << endl;
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
