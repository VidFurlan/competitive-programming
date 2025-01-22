#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
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
    int n, x; cin >> n >> x;
    vi a(n);
    FOR(i, n) cin >> a[i];
    auto findPos = [&]() -> int {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[m] <= x) l = m;
            else r = m;
        }
        return l;
    };
    int idx = findPos();
    int pos = 0;
    for (; pos < n; pos++) if (a[pos] == x) break;
    cout << 1 << endl;
    cout << pos + 1 << " " << idx + 1 << endl;
    //FORR(x, a) cout << x << " "; cout << endl;
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
