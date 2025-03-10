#include <iomanip>
#include <iostream>
#include <vector>
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
    int n = SZ(s), m; cin >> m;
    string l, r; cin >> l >> r;
    int pos = 0;
    FOR(i, m) {
        vi seen(10, INF);
        REP(j, pos, n-1) {
            if (seen[s[j]-'0'] == INF) seen[s[j]-'0'] = j;
        }
        int mx = -1;
        //cout << i << ": "; FORR(x, seen) cout << setw(4) << (x == INF ? -1 : x) << " "; cout << endl;
        REP(j, l[i]-'0', r[i]-'0') {
            if (seen[j] == INF) {
                cout << "YES" << endl;
                return;
            }
            mx = max(mx, seen[j]);
        }
        pos = mx+1;
    }
    cout << "NO" << endl;
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
