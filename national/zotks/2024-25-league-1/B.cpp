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
    string s; cin >> s;
    FORR(c, s) c -= '0';
    ll n = SZ(s);
    if (n != 8) {
        cout << 0 << endl;
        return;
    }
    ll v = 2 * s[6] + 3 * s[5] + 4 * s[4] + 5 * s[3] + 6 * s[2] + 7 * s[1] + 8 * s[0];
    ll o = v % 11;
    ll r = 11 - o;
    if (r == 10) {
        if (s[7] != 0) {
            cout << 0 << endl;
            return;
        }
    }
    else if (r == 11) {
        cout << 0 << endl;
        return;
    }
    else {
        if (s[7] != r) {
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
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
