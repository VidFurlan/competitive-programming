#include <iostream>
#include <vector>
#include <algorithm>
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
    ll b, c, d; cin >> b >> c >> d;
    ll rev = 0;
    int sz = 0;
    while (b || c || d) {
        sz++;
        int bb = b & 1; b >>= 1;
        int cc = c & 1; c >>= 1;
        int dd = d & 1; d >>= 1;
        if ((!bb && cc && dd) || (bb && !cc && !dd)) {
            cout << "-1" << endl;
            return;
        }
        rev <<= 1;
        //cout << bb << cc << dd << " ";
        if ((bb && cc && !dd) || (!bb && !cc && dd)) {
            rev |= 1;
        }
        //debug(rev&1);
    }
    ll ans = 0;
    FOR(i, sz) {
        ans <<= 1;
        ans |= rev & 1;
        rev >>= 1;
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
