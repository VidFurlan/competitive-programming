#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
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
    vi a(n);
    FOR(i, n) cin >> a[i];
    sort(ALL(a));
    vi b(1, 1);
    REP(i, 1, n - 1) {
        if (a[i] == a[i - 1]) {
            b.back()++;
        } 
        else {
            b.push_back(1);
        }
    }
    int m = b.size();
    vi dp(m + 1, INF);
    dp[0] = 0;

    REP(i, 1, m) {
        vi dp2 = dp;
        REP(k, 1, m)
            if (dp[k - 1] + b[i - 1] <= i - k)
                dp2[k] = min(dp2[k], dp[k - 1] + b[i - 1]);

        dp = dp2;
    }

    int ans = m;
    while (dp[ans] >= INF) ans--;
    cout << m - ans << endl;
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
