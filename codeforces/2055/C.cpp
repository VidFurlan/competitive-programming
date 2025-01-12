#include <bits/stdc++.h>
#include <numeric>
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
    string s; cin >> s;
    vvl a(n, vl(m));
    FOR(i, n) FOR(j, m) cin >> a[i][j];

    ll target = 0;
    vl rowSum(n), colSum(m);
    FOR(i, n) rowSum[i] = accumulate(ALL(a[i]), 0LL);
    FOR(j, m) FOR(i, n) colSum[j] += a[i][j];

    //FORR(x, rowSum) cout << x << " "; cout << endl;
    //FORR(x, colSum) cout << x << " "; cout << endl;
    ll x = 0, y = 0;
    REP(i, 0, SZ(s)-1) {
        if (s[i] == 'D') {
            ll need = target - rowSum[x];
            a[x][y] += need;
            rowSum[x] += need;
            colSum[y] += need;
            x++;
        }
        else {
            ll need = target - colSum[y];
            a[x][y] += need;
            rowSum[x] += need;
            colSum[y] += need;
            y++;
        }
    }
    if (s.back() == 'D') {
        ll need = target - rowSum.back();
        a[n-1][m-1] += need;
        rowSum[n-1] += need;
        colSum[m-1] += need;
    }
    else {
        ll need = target - colSum.back();
        a[n-1][m-1] += need;
        rowSum[n-1] += need;
        colSum[m-1] += need;
    }

    FORR(x, a) {
        FORR(y, x) cout << y << " ";
        cout << endl;
    }

    FOR(i, n) {
        ll sum = 0;
        FOR(j, m) {
            sum += a[i][j];
        }
        assert(sum == target);
    }
    FOR(j, m) {
        ll sum = 0;
        FOR(i, n) {
            sum += a[i][j];
        }
        assert(sum == target);
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
