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
    int n, m; cin >> n >> m;
    vl a(n), b(m);
    ll mx = 0;
    FOR(i, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    FOR(i, m) cin >> b[i];
    if (mx > b[0]) {
        cout << -1 << endl;
        return;
    }
    vl dp(n+1, LLINF);
    dp[0] = 0;
    FOR(i, m) {
        ll sum = 0;
        int sz = 0;
        FOR(j, n) {
            sum += a[j];
            sz++;
            while (sz && sum > b[i]) {
                sum -= a[j-sz+1];
                sz--;
            }
            //cout << j << " sum: " << sum << " sz: " << sz << endl;
            if (sz == 0) {
                if (dp[j+1] == LLINF) break;
                continue;
            }
            if (sz) {
                dp[j+1] = min(dp[j+1], dp[j-sz+1] + m - i - 1);
            }
        }
        //FORR(x, dp) cout << x << " ";
        //cout << endl;
    }
    //FORR(x, dp) cout << x << " ";

    cout << dp.back() << endl;
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
