#include <algorithm>
#include <bits/stdc++.h>
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
    int n; cin >> n;
    vl a(n);
    ll ans = 0;
    vector<bitset<4>> dp(n);
    FOR(i, n) {
        cin >> a[i];
        if (a[i] < 5) {
            if (a[i] >= 1) dp[i][0] = 1;
            if (a[i] >= 2) dp[i][1] = 1;
            if (a[i] >= 3) dp[i][2] = 1;
            if (a[i] >= 4) dp[i][3] = 1;
        }
        else {
            ans++;
        }
    }
    FOR(i, n) {
        if (dp[i] == 0) continue;
        if (i + 1 < n && a[i + 1] <= 2 && a[i] >= 3) {
            ans++;
            dp[i] = 0;
            continue;
        }
        if (dp[i][0] && i + 1 < n && dp[i + 1][0]) {
            ans++;
            dp[i][0] = 0;
            dp[i][1] = 0;
            if (i + 1 < n) {
                dp[i + 1][0] = 0;
                dp[i + 1][1] = 0;
            }
        }
        if (dp[i][2] && i + 1 < n && dp[i + 1][2]) {
            ans++;
            dp[i][2] = 0;
            dp[i][3] = 0;
            if (i + 1 < n) {
                dp[i + 1][2] = 0;
                dp[i + 1][3] = 0;
                if (a[i + 1] > 2)
                    a[i + 1] = 2;
            }
        }

        if (dp[i] != 0) {
            ans++;
            dp[i] = 0;
        }
    }

    //FORR(x, dp) {
    //    cout << x[0] << x[1] << x[2] << x[3] << endl;
    //}
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
