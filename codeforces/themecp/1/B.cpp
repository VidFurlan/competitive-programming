#include <bits/stdc++.h>
#include <tuple>
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
    int n; cin >> n;
    vector<pair<pii, int>> a(n);
    FOR(i, n) cin >> a[i].fi.fi;
    FOR(i, n) cin >> a[i].fi.se;
    FOR(i, n) a[i].se = i;
    sort(ALL(a), [&](pair<pii, int> &b, pair<pii, int> &c) {
        return b.fi < c.fi;
    });
    //FORR(x, a) cout << x.fi.fi << " "; cout << endl;
    //FORR(x, a) cout << x.fi.se << " "; cout << endl;
    //FORR(x, a) cout << x.se << " "; cout << endl;
    FOR(i, n-1) {
        if (a[i].fi.se > a[i+1].fi.se) {
            cout << -1 << endl;
            return;
        }
    }

    vector<pii> ans;
    vi b(n);
    FOR(i, n) {
        b[a[i].se] = i;
    }
    //FORR(x, b) cout << x << " "; cout << endl;
    FOR(i, n) {
        while (b[i] != i) {
            int tar = b[i];
            ans.push_back({i, tar});
            swap(b[i], b[tar]);
        }
    }
    cout << SZ(ans) << endl;
    FORR2(x, y, ans) cout << x + 1 << " " << y + 1 << endl;
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
