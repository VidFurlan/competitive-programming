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
    vector<pii> a(n);
    FOR(i, n) cin >> a[i].first >> a[i].second;
    vi f(2*n+1);
    FORR2(l, r, a) if (l == r) f[l]++;
    vi pref(2*n+1);
    REP(i, 1, 2*n) pref[i] = pref[i-1] + (f[i] > 0);
    string ans;
    FOR(i, n) {
        auto [l, r] = a[i];
        if (l == r) {
            if (f[l] == 1) ans += '1';
            else ans += '0';
        }
        else {
            int tot = r - l + 1;
            int cnt = pref[r] - pref[l-1];
            if (cnt < tot) ans += '1';
            else ans += '0';
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
