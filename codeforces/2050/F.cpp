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

vi segTree;
int m;

void buildSegTree(vi& arr, int n) {
    FOR(i, n) segTree[n + i] = arr[i];
    REPR(i, n - 1, 0) 
        segTree[i] = gcd(segTree[2 * i], segTree[2 * i + 1]);
}

int query(int l, int r) {
    int ans = 0;
    l += m;
    r += m;
    while (l < r) {
        if (l % 2 == 1) {
            ans = gcd(ans, segTree[l]);
            l++;
        }
        if (r % 2 == 1) {
            r--;
            ans = gcd(ans, segTree[r]);
        }
        l /= 2;
        r /= 2;
    }
    return ans;
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    FOR(i, n) cin >> a[i];

    vi diff;
    if (n > 1) REP(i, 1, n - 1) diff.push_back(a[i] - a[i - 1]);
    m = SZ(diff);

    segTree = vi(2 * m);
    if (m) buildSegTree(diff, m);

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (l == r ? 0 : query(l - 1, r - 1)) << " ";
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
