#include <iostream>
#include <vector>
#include <algorithm>
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
    ll n, k; cin >> n >> k;
    vector<pll> a(n);
    FORR(x, a) cin >> x.fi;
    FORR(x, a) cin >> x.se;
    sort(ALL(a));
    ll ans = 0;
    ll m = (n - 2) / 2;

    FOR(i, n) {
        ll sum = a[i].fi + (i <= m ? a[m + 1].fi : a[m].fi);
        if (a[i].se) sum += k;
        ans = max(ans, sum);
    }

    ll mx = a.back().fi;
    a.pop_back();
    n--;
    
    ll low = 0, high = 2e9;
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        ll k2 = k;
        ll ok = 0;

        for (int i = n-1; i >= 0; i--) {
            if (a[i].fi >= mid) ok++;
            else if (a[i].se && a[i].fi + k2 >= mid) {
                k2 -= mid - a[i].fi;
                ok++;
            }
        }

        if (ok + m >= n) low = mid;
        else high = mid - 1;
    }

    cout << max(ans, mx + low) << endl;
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
