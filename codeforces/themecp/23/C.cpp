#include <bits/stdc++.h>
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
    int n, s1, s2; cin >> n >> s1 >> s2;
    vector<pii> r(n);
    FOR(i, n) {
        cin >> r[i].fi;
        r[i].se = i;
    }
    sort(RALL(r));
    vi t(n);
    int t1 = s1, t2 = s2;
    FOR(i, n) {
        if (t1 < t2) {
            t[i] = 0;
            t1 += s1;
        }
        else {
            t[i] = 1;
            t2 += s2;
        }
    }
    vvi ans(2);
    FOR(i, n) {
        ans[t[i]].push_back(r[i].se + 1);
    }
    FORR(r, ans) {
        cout << SZ(r) << " ";
        FORR(x, r) cout << x << " ";
        cout << endl;
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
