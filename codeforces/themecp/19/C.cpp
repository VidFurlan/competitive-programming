#include <iostream>
#include <map>
#include <numeric>
#include <vector>
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
    vi a(n);
    FOR(i, n) cin >> a[i];
    int bad = 0;
    FOR(i, n) bad ^= abs(a[i]);
    if (bad) {
        cout << -1 << endl;
        return;
    }
    int tot = a[0];
    REP(i, 1, n-1) tot += a[i];
    vi b(n);
    iota(ALL(b), 1);
    int i = 1;
    while (tot != 0) {
        if (tot < 0 && a[i] == -1) {
            b[i] = b[i-1];
            tot += 2;
            i++;
        }   
        if (tot > 0 && a[i] == 1) {
            b[i] = b[i-1];
            tot -= 2;
            i++;
        }
        i++;
        if (i >= n) break;
    }
    //cout << "b: "; FORR(x, b) cout << x << " "; cout << endl;
    map<int, pii> mp;
    FOR(i, n) {
        if (mp.count(b[i])) {
            mp[b[i]].se = i;
        }
        else {
            mp[b[i]] = {i, i};
        }
    } 
    cout << SZ(mp) << endl;
    FORR2(x, y, mp) {
        cout << y.fi + 1 << " " << y.se + 1 << endl;
    }
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
