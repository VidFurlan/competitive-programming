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
    ll n, x, m = 0; cin >> n >> x;
    map<ll, ll> dp;
    dp[0] = 0; // Happiness, Cost
    FOR(i, n) {
        map<ll, ll> dp2 = dp;
        ll c, h; cin >> c >> h;
        FORR2(happy, cost, dp) {
            if (m < cost + c) continue;
            dp2[happy + h] = min((dp2[happy + h] == 0 ? LLINF : dp2[happy + h]), cost + c);
            //cout << "happy: " << happy + h << " cost: " << dp2[happy + h] << endl;
        }
        dp = dp2;
        m += x;
    }
    cout << dp.rbegin()->fi << endl;
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
