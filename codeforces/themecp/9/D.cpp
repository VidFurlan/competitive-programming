#include <bits/stdc++.h>
#include <unordered_set>
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
    ll n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    unordered_set<char> diff;
    FOR(i, n) {
        if (a[i] != b[i]) diff.insert(a[i]);
    }
    ll ans = 0;
    if (SZ(diff) <= k) {
        ans = (n + 1) * n / 2;
    }
    else {
        int tot = 1 << SZ(diff);
        vi allCh(ALL(diff));
        FOR(mask, tot) {
            vi use(26);
            int cur = 0, pos = 0;
            for (int i = mask; i > 0; i >>= 1) {
                if (i & 1) {
                    use[allCh[pos] - 'a'] = 1;
                    cur++;
                }
                pos++;
            }
            if (cur != k) continue;
            //cout << mask << endl;
            ll sz = 0;
            ll res = 0;
            FOR(i, n) {
                if (a[i] == b[i] || use[a[i] - 'a'] == 1) {
                    sz++;
                }
                else {
                    res += (sz + 1) * sz / 2;
                    sz = 0;
                }
            }
            res += (sz + 1) * sz / 2;
            ans = max(ans, res);
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
