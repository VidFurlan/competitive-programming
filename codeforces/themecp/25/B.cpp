#include <bits/stdc++.h>
#include <iomanip>
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
    vl a(n);
    FOR(i, n) cin >> a[i];
    ll ans = 0;
    for (int i = 1; i < n-1; i += 2) {
        if (a[i] > a[i-1] && a[i] > a[i+1]) continue;
        ans += max(a[i-1], a[i+1]) - a[i] + 1;
    }
    if (n % 2 == 0) {
        vl pref(n), suff(n);
        for (int i = 1; i < n-1; i += 2) {
            if (i - 2 >= 0) pref[i] = pref[i - 2];
            if (a[i] > a[i-1] && a[i] > a[i+1]) continue;
            pref[i] += max(a[i-1], a[i+1]) - a[i] + 1;
        }
        for (int i = 2; i < n-1; i += 2) {
            if (i - 2 >= 0) pref[i] = pref[i - 2];
            if (a[i] > a[i-1] && a[i] > a[i+1]) continue;
            pref[i] += max(a[i-1], a[i+1]) - a[i] + 1;
        }
        for (int i = n-2; i > 0; i -= 2) {
            if (i + 2 < n) suff[i] = suff[i + 2];
            if (a[i] > a[i-1] && a[i] > a[i+1]) continue;
            suff[i] += max(a[i-1], a[i+1]) - a[i] + 1;
        }
        for (int i = n-3; i > 0; i -= 2) {
            if (i + 2 < n) suff[i] = suff[i + 2];
            if (a[i] > a[i-1] && a[i] > a[i+1]) continue;
            suff[i] += max(a[i-1], a[i+1]) - a[i] + 1;
        }
        for (int i = 4; i < n-1; i++) {
            ans = min(ans, pref[i-2] + suff[i]);
            if (i % 2 == 0) ans = min(ans, pref[i-3] + suff[i]);
        }
        if (n == 4) {
            ans = min({suff[1], pref[2], ans});
        }
        //FORR(x, pref) cout << setw(3) << x << " "; cout << endl;
        //FORR(x, suff) cout << setw(3) << x << " "; cout << endl;
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
