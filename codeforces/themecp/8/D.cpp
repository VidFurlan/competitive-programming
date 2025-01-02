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
    vvi a(n, vi(m));
    FOR(i, n) FOR(j, m) cin >> a[i][j];
    int tot = 0;
    FOR(i, n) tot += accumulate(ALL(a[i]), 0);
    if (tot % n) {
        cout << -1 << endl;
        return;
    }
    int row = tot / n;
    map<int, int> mp;
    FOR(i, n) {
        int cnt = accumulate(ALL(a[i]), 0);
        if (cnt - row != 0) mp[i] = cnt - row;
    }
    
    vvi ans; 

    FOR(c, m) {
        set<int> need, have;
        FOR(r, n) {
            if (mp[r] < 0 && a[r][c] == 0) need.insert(r);
            else if (mp[r] > 0 && a[r][c] == 1) have.insert(r);
        }

        while (SZ(need) && SZ(have)) {
            ans.push_back({*need.begin(), *have.begin(), c});
            mp[*need.begin()]++;
            mp[*have.begin()]--;
            need.erase(need.begin());
            have.erase(have.begin());
        }
    }

    cout << SZ(ans) << endl;
    FORR(x, ans) cout << x[0] + 1 << " " << x[1] + 1 << " " << x[2] + 1 << endl;
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
