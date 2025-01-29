#include <bits/stdc++.h>
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
    vvi a(n);
    vi b;
    FOR(i, n) {
        int m; cin >> m;
        a[i] = vi(m);
        FOR(j, m) {
            cin >> a[i][j];
            b.push_back(a[i][j]);
        }
    }
    sort(ALL(b));
    map<int, int> mp;
    FOR(i, SZ(b)) mp[b[i]] = i;
    FORR(t, a) FORR(x, t) x = mp[x];
    //FOR(i, n) {FORR(x, a[i]) cout << x << " "; cout << endl;}
    int ans = 0;
    FOR(i, n) {
        FOR(j, SZ(a[i])-1) {
            if (a[i][j] + 1 != a[i][j+1]) ans++;
        }
    }
    cout << ans << " " << ans + n - 1 << endl;
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
