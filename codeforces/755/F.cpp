#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
using namespace std;
#define SINGLE_TEST 1

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
const ll INF = 1e9;
const ll LLINF = 1e18;
const int MAXN = 1e6 + 5;

void solve() {
    ll n, k; cin >> n >> k;
    vl p(n);
    FORR(x, p) { cin >> x; x--; }
    vl cnt(MAXN, 0);
    bitset<MAXN> seen;
    ll c1 = 0, c2 = 0;
    FOR(i, n) {
        if (seen[i]) continue;
        ll c = 0, j = i;
        while (!seen[j]) {
            seen[j] = 1;
            j = p[j];
            c++;
        }
        c1 += c % 2;
        c2 += c / 2;
        cnt[c]++;
    }

    bitset<MAXN> dp;
    dp[n] = 1;
    REP(i, 1, n) {
        if (cnt[i] == 0) continue;
        int j = 1;
        while (cnt[i] > 0) {
            j = min(j * 1ll, cnt[i]);
            dp |= dp >> (i * j);
            cnt[i] -= j;
            j *= 2;
        }
    }

    int mn = k + !dp[n - k];
    int mx = 2 * min(k, c2);
    k -= min(k, c2);
    mx += min(k, c1);
    cout << mn << " " << mx << endl;
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
