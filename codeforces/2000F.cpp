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

vl dp(101, INF);
vl dp2(101, INF);
void solve() {
    int n, k; cin >> n >> k;
    dp.assign(k + 1, INF);
    dp[0] = 0;
    while (n--) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        dp2.assign(k + 1, INF);
        dp2[0] = 0;
        ll cost = 0, cnt = 0;
        ll xt = x, yt = y;
        REP(i, 1, x + y - 1) {
            if (cnt > k) break;
            cnt++;
            if (xt < yt) {
                cost += xt;
                dp2[cnt] = min(dp2[cnt], cost);
                yt--;
            }
            else {
                cost += yt;
                dp2[cnt] = min(dp2[cnt], cost);
                xt--;
            }

            if (cnt == x + y - 1) {
                cnt++;
                dp2[cnt] = min(dp2[cnt], cost);
            }
        }

        REPR(i, k, 1) {
            REP(j, 1, cnt) {
                if (i - j < 0) break;
                dp[i] = min({dp2[i - j] + dp[j], dp[i - j] + dp2[j], dp2[i], dp[i]});
            }
        }
    }
    cout << ((dp[k] == INF) ? -1 : dp[k]) << endl;
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
