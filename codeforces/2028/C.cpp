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
    ll n, m, v; cin >> n >> m >> v;
    vl a(n);
    FOR(i, n) cin >> a[i];
    vl pref(n + 1), suff(n + 1);
    FOR(i, n) pref[i + 1] = pref[i] + a[i];
    REPR(i, n - 1, 0) suff[i] = suff[i + 1] + a[i];

    vl vpref(n + 1), vsuff(n + 1);
    ll sum = 0;
    FOR(i, n) {
        if (sum + a[i] < v) {
            sum += a[i];
            vpref[i + 1] = vpref[i];
        } 
        else {
            sum = 0;
            vpref[i + 1] = vpref[i] + 1;
        }
    }
    sum = 0;
    REPR(i, n - 1, 0) {
        if (sum + a[i] < v) {
            sum += a[i];
            vsuff[i] = vsuff[i + 1];
        } 
        else {
            sum = 0;
            vsuff[i] = vsuff[i + 1] + 1;
        }
    }

    //FORR(x, vpref) cout << x << " ";
    //cout << endl;
    //FORR(x, vsuff) cout << x << " ";
    //cout << endl;

    ll ans = -1;
    ll l = 0, r = 0;
    while (r <= n) {
        if (vpref[l] + vsuff[r] >= m) {
            ans = max(ans, pref[r] - pref[l]);
            r++;
        } 
        else if (l < r) {
            l++;
        }
        else {
            l++;
            r++;
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
