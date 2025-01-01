#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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
    if (k >= 3) {
        cout << 0 << endl;
        return;
    }
    set<ll> b;
    FOR(i, n) REP(j, i+1, n-1) b.insert(abs(a[i] - a[j]));
    sort(ALL(a));
    ll ans = min(a[0], *b.begin());
    if (k == 1) {
        cout << ans << endl;
        return;
    }
    FOR(i, n) {
        auto it = b.lower_bound(a[i]);
        if (it == b.end()) {
            ans = min(ans, abs(*prev(it) - a[i]));
        }
        else if (it == b.begin()) {
            ans = min(ans, abs(*it - a[i]));
        }
        else {
            ans = min({ans, abs(*prev(it) - a[i]), abs(*it - a[i])});
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
