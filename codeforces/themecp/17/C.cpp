#include <bits/stdc++.h>
#include <cstdlib>
#include <numeric>
#include <utility>
using namespace std;
#define SINGLE_TEST 1

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
    ll cnt[2] = {0};
    FORR(c, s) cnt[(c == '+')]++;
    int q; cin >> q;
    ll diff = cnt[0] - cnt[1];
    //cout << endl;
    //cout << cnt[0] << " " << cnt[1] << endl;
    while (q--) {
        ll x, y; cin >> x >> y;
        if (x == y) cout << (cnt[0] == cnt[1] ? "YES" : "NO") << endl;
        else {
            ll d = diff * y / (x - y);
            cout << (-cnt[0] <= d && d <= cnt[1] && diff * y % (x - y) == 0 ? "YES" : "NO") << endl;
        }
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
