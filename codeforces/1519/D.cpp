#include <bits/stdc++.h>
using namespace std;
#define SINGLE_TEST 1

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
    ll n; cin >> n;
    vl a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];
    ll tot = 0;
    FOR(i, n) tot += a[i]*b[i];
    ll ans = tot;
    FOR(i, n) {
        ll cur = tot;
        REP(sz, 1, n) {
            if (i-sz < 0 || i+sz >= n) break;
            cur += a[i-sz]*b[i+sz];
            cur += a[i+sz]*b[i-sz];
            cur -= a[i-sz]*b[i-sz];
            cur -= a[i+sz]*b[i+sz];
            ans = max(ans, cur);
        }
        cur = tot;
        REP(sz, 1, n) {
            if (i-sz+1 < 0 || i+sz >= n) break;
            cur += a[i-sz+1]*b[i+sz];
            cur += a[i+sz]*b[i-sz+1];
            cur -= a[i-sz+1]*b[i-sz+1];
            cur -= a[i+sz]*b[i+sz];
            ans = max(ans, cur);
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
