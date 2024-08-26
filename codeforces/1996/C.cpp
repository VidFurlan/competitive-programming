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
    int n, q; cin >> n >> q;
    string s1, s2; cin >> s1 >> s2;
    vvi dp1(n+1, vi(26));
    vvi dp2(n+1, vi(26));
    FOR(i, n) {
        dp1[i + 1] = dp1[i];
        dp1[i + 1][s1[i] - 'a']++;
        dp2[i + 1] = dp2[i];
        dp2[i + 1][s2[i] - 'a']++;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        vi cnt1 = dp1[r], cnt2 = dp2[r];
        FOR(i, 26) {
            cnt1[i] -= dp1[l-1][i];
            cnt2[i] -= dp2[l-1][i];
        }
        int ans = 0;
        FOR(i, 26) {
            ans += abs(cnt1[i] - cnt2[i]);
        }
        ans /= 2;
        cout << ans << endl;
    }
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
