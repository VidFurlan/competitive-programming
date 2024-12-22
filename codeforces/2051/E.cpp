#include <algorithm>
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
    ll n, k; cin >> n >> k;
    vl a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    vl c(2*n);
    FOR(i, n) c[i] = a[i];
    FOR(i, n) c[i+n] = b[i];
    sort(ALL(c));
    c.erase(unique(ALL(c)), c.end());
    ll m = SZ(c);
    vl posDif(m+2), buyDif(m+2);
    FOR(i, n) {
        ll x = lower_bound(ALL(c), a[i]) - c.begin() + 1;
        ll y = lower_bound(ALL(c), b[i]) - c.begin() + 1;
        posDif[1]++, buyDif[1]++;
        if (x+1 <= m) posDif[x+1]--;
        if (y+1 <= m) buyDif[y+1]--;
    }

    vl pos(m+1), buy(m+1);
    REP(i, 1, m) {
        pos[i] = pos[i-1] + posDif[i];
        buy[i] = buy[i-1] + buyDif[i];
    }

    ll ans = 0;
    REP(i, 1, m) {
        if (buy[i] - pos[i] <= k) ans = max(ans, c[i-1] * buy[i]);
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
