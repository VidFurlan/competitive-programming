#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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
    int n; cin >> n;
    vi p(n); 
    FOR(i, n) cin >> p[i];
    vi q(n);
    
    bool isOdd = 0;
    FOR(i, n) if (i % 2 && p[i] == 1) { isOdd = 1; break; }
    if (isOdd) REVERSE(p);

    vector<pii> even, odd;
    FOR(i, n) {
        if (i & 1) odd.push_back({p[i], i});
        else even.push_back({p[i], i});
    }
    sort(RALL(even));
    sort(RALL(odd));
    FORR(x, odd) even.push_back(x);
    FOR(i, n) q[even[i].se] = i + 1;
    if (isOdd) REVERSE(q);
    FORR(x, q) cout << x << " "; cout << endl;

    //int ans = 0;
    //REP(i, 1, n-2) ans += (p[i-1] + q[i-1] < p[i] + q[i]) && (p[i+1] + q[i+1] < p[i] + q[i]);
    //debug(ans);
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
