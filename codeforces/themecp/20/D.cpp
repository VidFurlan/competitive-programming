#include <iostream>
#include <map>
#include <string>
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
    int n, m; cin >> n >> m;
    vvi a(n, vi(m));
    FOR(i, n) FOR(j, m) cin >> a[i][j];
    vvi b(n, vi(m));
    map<string, int> mp;
    FOR(i, n) {
        FOR(j, m) {
            b[i][a[i][j] - 1] = j + 1;
        }
        string s;
        FORR(x, b[i]) {
            s += to_string(x) + " ";
            mp[s]++;
        }
    }
    //FORR(x, b) {FORR(y, x) cout << y << " "; cout<<endl;}
    FOR(i, n) {
        int ans = 0;
        string s;
        FOR(j, m) {
            s += to_string(a[i][j]) + " ";
            if (mp.count(s)) ans = j + 1;
        }
        cout << ans << " ";
    }
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
