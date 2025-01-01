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
    int n, k; cin >> n >> k;
    vi a(n);
    FOR(i, n) cin >> a[i];
    vvi worst(k + 1);
    vi last(k + 1, -1);
    FOR(i, n) {
        int cur = a[i] - 1;
        worst[cur].push_back(i - last[cur] - 1);
        last[cur] = i;
    }
    FOR(i, k) {
        worst[i].push_back(n - last[i] - 1);
        sort(ALL(worst[i]));
        worst[i].back() /= 2;
        //cout << i + 1 << ": "; FORR(x, worst[i]) cout << x << " "; cout << endl;
    }
    int ans = INF;
    FOR(i, k) {
        int m = SZ(worst[i]);
        if (m == 1) {
            ans = min(ans, worst[i][0]);
        }
        else {
            ans = min(ans, max(worst[i][m - 1], worst[i][m - 2]));
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
