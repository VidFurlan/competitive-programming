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
    vector<string> a(n);
    FOR(i, n) cin >> a[i];
    vi dp(5, -INF);
    dp[0] = 0;
    const string s = "narek";
    FOR(i, n) {
        vi cur = dp;
        int loss = 0;
        FORR(c, a[i]) if (s.find(c) != string::npos) loss += 1;
        FOR(st, 5) {
            int idx = st;
            int full = 0;
            FOR(j, m) {
                if (a[i][j] == s[idx%5]) {
                    idx++;
                    if (idx%5 == 0) full++;
                    cur[idx%5] = max(cur[idx%5], dp[st] - loss + full * 10);
                }
            }
        }
        //FORR(x, cur) cout << x << " "; cout << endl;
        dp = cur;
    }
    cout << *max_element(ALL(dp)) << endl;
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
