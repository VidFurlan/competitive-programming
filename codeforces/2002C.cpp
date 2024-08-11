#include <cmath>
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
    ll n; cin >> n;
    vector<pair<long double, long double>> a(n);
    FORR(x, a) cin >> x.fi >> x.se;
    pair<long double, long double> start, end; cin >> start.fi >> start.se >> end.fi >> end.se;
    long double minDist = LLINF;
    long double distToFinish = sqrtl(powl(start.fi - end.fi, 2) + powl(start.se - end.se, 2));
    FORR(x, a) {
        minDist = min(minDist, sqrtl(powl(end.fi - x.fi, 2) + powl(end.se - x.se, 2)));
    }
    if (distToFinish < minDist)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
