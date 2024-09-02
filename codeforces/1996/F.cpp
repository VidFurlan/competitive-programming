#include <algorithm>
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
    ll n, k, ans = 0; cin >> n >> k;
    vl a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    ll low = 0, high = INF + 1;
    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        ll sum = 0;
        
        FOR(i, n) {
            if (a[i] >= mid) {
                sum += (a[i] - mid) / b[i] + 1;
            }
        }

        if (sum >= k) {
            low = mid;
        } else {
            high = mid;
        }
    }

    ll m = 0;
    FOR(i, n) {
        if (a[i] >= low) {
            ll kk = (a[i] - low) / b[i] + 1;
            ans += kk * a[i] - kk * (kk - 1) / 2 * b[i];
            m += kk;
        }
    }

    ans -= low * (m - k);

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
