#include <bits/stdc++.h>
#include <iterator>
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
    vi lpref(n), rpref(n);
    lpref[0] = -1;
    REP(i, 0, n-1) {
        if (i > 0) lpref[i] = lpref[i - 1];
        if (s[i] == '0') lpref[i] = i;
    }

    rpref[n - 1] = n;
    REPR(i, n-1, 0) {
        if (i + 1 < n) rpref[i] = rpref[i + 1];
        if (s[i] == '1') rpref[i] = i;
    }

    set<pii> perm;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        if (rpref[l - 1] > lpref[r - 1]) perm.insert({-1, -1});
        else perm.insert({rpref[l - 1], lpref[r - 1]});
    }
    cout << SZ(perm) << endl;
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
