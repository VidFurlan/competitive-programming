#include <numeric>
#include <set>
#include <vector>
#include <iostream>
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
    int n, x; cin >> n >> x;
    vi a(n);
    FOR(i, n) cin >> a[i];
    int ans = 1;
    set<int> dp = {1};
    for (int i = 0; i < n; i++) {
        if (x % a[i] != 0) continue;

        set<int> dp2 = dp;
        FORR(y, dp) {
            if (x % (y * a[i]) == 0) {
                dp2.insert(y * a[i]);
            }
        }
        
        dp = dp2;

        if (dp.find(x) != dp.end()) {
            ans++;
            dp = {1, a[i]};
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
