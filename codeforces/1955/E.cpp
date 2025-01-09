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
    int n; cin >> n;
    string s; cin >> s;
    FORR(c, s) c -= '0';
    int ans = 1;
    REP(m, 2, n) {
        vi reset(n + 1);
        bool flip = 0;
        bool ok = 1;
        //debug(m);
        FOR(i, n) {
            flip ^= reset[i];
            //cout << '\t'; debug(flip);
            if ((s[i] ^ flip) == 0) {
                flip ^= 1;
                if (i + m - 1 < n) {
                    reset[i + m] ^= 1;
                }
                else {
                    ok = 0;
                    break;
                }
            } 
            //cout << '\t'; FORR(x, reset) cout << x; cout << endl;
        }
        if (ok) {
            ans = m;
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
