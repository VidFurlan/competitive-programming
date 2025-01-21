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
    ll n, m, d; cin >> n >> m >> d;
    vl a(m+2);
    a[0] = 1-d;
    a[m+1] = n+1;
    FOR(i, m) cin >> a[i+1];
    ll base = 0;
    REP(i, 1, m+1) {
        base += (a[i] - a[i-1] - 1) / d;
    }
    //debug(base);
    ll ans = LLINF;
    ll cnt = 0;
    REP(i, 1, m) {
        ll cur = base + m - 1;
        cur -= (a[i] - a[i-1] - 1) / d;
        cur -= (a[i+1] - a[i] - 1) / d;
        cur += (a[i+1] - a[i-1] - 1) / d;
        if (cur < ans) {
            //cout << ans << "->" << cur << endl;
            ans = cur;
            cnt = 0;
        }
        if (ans == cur) cnt++;

        //cout << i << ": "; debug(cur);
    }
    cout << ans << " " << cnt << endl;
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
