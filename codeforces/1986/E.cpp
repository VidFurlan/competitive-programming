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
    ll n, k; cin >> n >> k;
    vl a(n);
    FORR(x, a) cin >> x;
    map<ll, set<ll>> cnt;
    FORR(x, a) {
        ll y = x % k;
        if (cnt[y].find(x) != cnt[y].end())
            cnt[y].erase(x);
        else
            cnt[y].insert(x);
    }

    bool odd = 0;
    ll ans = 0;
    FORR2(key, v, cnt) {
        ll m = v.size();
        vl b(ALL(v));
        
        if (m % 2 == 1) {
            if (odd) {
                cout << -1 << endl;
                return;
            }
            odd = 1;

            vl suff(m + 1);
            for (int i = m - 2; i >= 0; i -= 2)
                suff[i] = (b[i + 1] - b[i]) / k + suff[i + 2];

            ll mn = suff[1];
            ll pref = 0;
            for (int i = 0; i < m - 1; i += 2) {
                pref += (b[i + 1] - b[i]) / k;
                mn = min(mn, pref + suff[i + 3]);
            }

            ans += mn;
        }
        else {
            FOR(i, m / 2)
                ans += (b[2 * i + 1] - b[2 * i]) / k;
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
