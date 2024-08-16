#include <bitset>
#include <iostream>
#include <vector>
#include <map>
#include <set>
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
    ll n, ans = 0; cin >> n;
    vi a(n); 
    FORR(x, a) { cin >> x; ans += x; }

    bitset<200002> s;

    FOR(i, 2) {
        int mx = 0;
        FOR(i, n) {
            if (s[a[i]]) {
                mx = max(mx, a[i]);
            }

            s[a[i]] = 1;
            a[i] = mx;
        }
        s.reset();
        if (i == 0)
            FORR(x, a) ans += x;
        else 
            FOR(i, n) ans += (n - i) * 1ll * a[i];
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
