#include <iostream>
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

void solve() {
    int x; cin >> x;
    vi a;
    int t = x;
    while (t) {
        a.push_back(t & 1);
        t >>= 1;
    }
    bool bad = 1;
    while (bad) {
        bad = 0;
        int n = SZ(a);
        REPR(i, n-2, 0) {
            if (a[i] == 1 && a[i+1] == 1) {
                a[i] = -1;
                a[i+1] = 0;
                if (i+2 < n) {
                    a[i+2] = 1;
                } else {
                    a.push_back(1);
                }
                bad = 1;
                break;
            }
            if (a[i] == 1 && a[i+1] == -1) {
                a[i] = -1;
                a[i+1] = 0;
                bad = 1;
                break;
            }
        }
    }
    cout << SZ(a) << endl;
    FORR(x, a) cout << x << " "; 
    cout << endl;
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
