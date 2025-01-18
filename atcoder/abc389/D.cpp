#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define SINGLE_TEST 1

typedef long long ll;
typedef long double ld;
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
    ll r; cin >> r;
    ll x = 1;
    ll ans = 0;
    while (true) {
        ll l = 0, h = r;
        ll mx = -1;
        while (l <= h) {
            ll m = (l + h) / 2;
            ll y = 2 * m + 1;
            ll dist = y * y + x * x;
            if (dist <= 4 * r * r) {
                mx = max(mx, m);
                l = m + 1;
            } 
            else {
                h = m - 1;
            }
        }
        //cout << x << " " << mx << endl;
        if (mx == -1) break;
        if (x == 1) ans += 2 * mx + 1;
        else ans += 4 * mx + 2;
        x += 2;
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
