#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
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

vl s;
vector<pll> comb;

void solve() {
    ll n; cin >> n;
    ll ans = INF;
    FORR2(num, c, comb) {
        ll need = n - num;
        ll cnt = c;
        if (need < 0) continue;
        while (need > 0) {
            cnt += need & 1;
            need >>= 1;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll fact = 1;
    REP(i, 1, 100) {
        if (fact * i > 1e12 || fact * i < 0) break;
        s.push_back(fact * i);
        fact *= i;
    }

    set<ll> un(ALL(s));
    un.erase(1ll);
    un.erase(2ll);
    s = vl(ALL(un));

    ll tot = 1ll << SZ(s);
    FOR(mask, tot) {
        ll sum = 0;
        ll cnt = 0;
        FOR(i, SZ(s)) {
            int f = 1 << i;
            if ((mask & f) != 0) {
                sum += s[i];
                cnt++;
            }
        }
        comb.push_back({sum, cnt});
    }

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
