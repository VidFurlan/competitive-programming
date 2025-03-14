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
    map<int, int> mp;
    FOR(i, n) mp[a[i]]++;
    map<int, bool> change;
    FORR2(x, y, mp) if (y > 1) change[x] = 1;
    int ok = 0;
    FORR2(x, y, mp) {
        if (y > 1) ok++;
    }
    if (ok < 2) {
        cout << -1 << endl;
    }
    else {
        vi b(n);
        bool f = 0;
        FOR(i, n) {
            if (!change[a[i]]) {
                b[i] = 1;
                continue;
            }

            if (mp[a[i]] > 1) b[i] = 1, mp[a[i]]--;
            else if (f) b[i] = 2;
            else b[i] = 3, f = 1;
        }
        FOR(i, n) cout << b[i] << " ";
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
