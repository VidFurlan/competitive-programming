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
    int n, m, q; cin >> n >> m >> q;
    set<int> a;
    FOR(i, m) {
        int x; cin >> x;
        a.insert(x);
    }

    while (q--) {
        int x; cin >> x;

        if (*a.begin() > x) {
            cout << *a.begin() - 1 << endl;
            continue;
        }
        else if (*a.rbegin() < x) {
            cout << n - *a.rbegin() << endl;
            continue;
        }

        if (a.find(x) != a.end()) {
            cout << 0 << endl;
            continue;
        }

        auto r = a.lower_bound(x);
        int l = *prev(r);
        int mid = (l + *r) / 2;
        cout << min(mid - l, *r - mid) << endl;
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
