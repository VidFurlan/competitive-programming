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
    int n; cin >> n;
    vi a(n);
    FOR(i, n) cin >> a[i];
    vector<pii> ans;
    int i0 = 0, i1 = n - 1;
    while (i0 < i1) {
        if (a[i0] != 1) {
            i0++;
            continue;
        }
        if (a[i1] != 0) {
            i1--;
            continue;
        }
        ans.push_back({i0, i1});
        swap(a[i0], a[i1]);
    }
    i0 = 0, i1 = n - 1;
    int i2 = n - 1;
    while (i0 < i1) {
        if (a[i1] == 2) {
            i1--;
            continue;
        }
        if (a[i0] != 2) {
            i0++;
            continue;
        }
        if (i2 >= 0 && a[i2] != 0) {
            i2--;
            continue;
        }
        a[i1] = 2;
        a[i0] = 1;
        ans.push_back({i0, i1});
        if (i0 < i2) {
            a[i0] = 0;
            a[i2] = 1;
            ans.push_back({i0, i2});
            i2--;
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
