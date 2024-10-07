#include <bits/stdc++.h>
#include <functional>
#include <vector>
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
    vi a(n + 1), b(m + 1), aIdx(n + 1);
    bitset<200005> bad;
    vector<set<int>> s(n + 1);
    int badCnt = 0;

    REP(i, 1, n) {
        cin >> a[i];
        aIdx[a[i]] = i;
    }
    REP(i, 1, m) {
        cin >> b[i];
        s[b[i]].insert(i);
    }

    REP(i, 1, n - 1) {
        if (!s[a[i + 1]].empty() && (s[a[i]].empty() || *s[a[i]].begin() > *s[a[i + 1]].begin())) {
            badCnt++;
            bad[i] = 1;
        }
    }
    cout << (badCnt == 0 ? "YA" : "TIDAK") << endl;

    function<void(int)> upd = [&](int x) {
        if (x >= n || x <= 0) return;
        if (!s[a[x + 1]].empty() && (s[a[x]].empty() || (*s[a[x]].begin() > *s[a[x + 1]].begin()))) {
            if (!bad[x]) badCnt++;
            bad[x] = 1;
        } else {
            if (bad[x]) badCnt--;
            bad[x] = 0;
        }
    };

    while (q--) {
        int x, y; cin >> x >> y;
        int oldVal = b[x];
        s[oldVal].erase(x);
        s[y].insert(x);
        b[x] = y;
        
        upd(aIdx[y]);
        upd(aIdx[y] - 1);
        upd(aIdx[oldVal]);
        upd(aIdx[oldVal] - 1);

        cout << (badCnt == 0 ? "YA" : "TIDAK") << endl;
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
        // cout << "---\n";
    }
#endif

    return 0;
}
