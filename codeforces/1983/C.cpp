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
    ll n; cin >> n;
    vvl a(3, vl(n));
    FOR(i, 3)
        FOR (j, n) 
            cin >> a[i][j];
    
    ll tot = 0;
    FORR(i, a[0]) tot += i;
    tot = (tot + 2) / 3;
    // cout << "tot" <<  tot << endl;
    
    vvl dp(3, vl(n, -1));
    FOR(i, 3) {
        ll sum = 0;
        ll l = 0, r = 0;
        while (l < n && r <= n) {
            if (sum < tot && r == n) break;

            if (sum < tot) {
                sum += a[i][r++];
            }
            else {
                sum -= a[i][l++];
            }
            
            if (sum >= tot)
                dp[i][l] = min(n - 1, r - 1);
        }
    }
    
    //FORR(i, dp) { FORR(j, i) cout << j << " "; cout << endl; }
    
    vector<pll> ans(3);
    FOR(i, 3) {
        FOR(j, 3) {
            if (i == j) continue;
            FOR(k, 3) {
                if (k == i || k == j) continue;

                ll pos1l = 0;
                if (dp[i][pos1l] == -1) continue;
                ll pos1r = dp[i][pos1l];
                ll pos2l = pos1r + 1;
                if (pos2l >= n || dp[j][pos2l] == -1) continue;
                ll pos2r = dp[j][pos2l];
                ll pos3l = pos2r + 1;
                if (pos3l >= n || dp[k][pos3l] == -1) continue;
                ll pos3r = dp[k][pos3l];

                ans[i] = {1, pos1r + 1};
                ans[j] = {pos2l + 1, pos2r + 1};
                ans[k] = {pos3l + 1, n};

                cout << ans[0].fi << " " << ans[0].se << " " << ans[1].fi << " " << ans[1].se << " " << ans[2].fi << " " << ans[2].se << endl;
                return;
                // cout << pos1 << " " << pos2 << " " << pos3 << endl;
            }
        }
    }
    
    cout << "-1" << endl;
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
