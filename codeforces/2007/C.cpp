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
    ll n, a, b; cin >> n >> a >> b;
    set<ll> c;
    FOR(i, n) {
        ll x; cin >> x;
        c.insert(x);
    }
    
    if (c.size() == 1) {
        cout << 0 << endl;
        return;
    }

    ll gc = gcd(a, b);
    set<ll> mods;
    FORR(x, c) {
        mods.insert(x % gc);
    }

    if (mods.size() == 1) {
        cout << 0 << endl;
        return;
    }

    vl v(ALL(mods));
    // FORR(x, v) cout << x << " ";
    ll ans = v.back() - v.front();
    n = v.size();
    REP(i, 1, n - 1) {
        ll diff = abs(v[i] - (v[i - 1] + gc));
        ans = min(ans, diff);
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
        // cout << "-------------------\n";
    }
#endif

    return 0;
}
