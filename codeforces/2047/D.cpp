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
    vi ans;
    vi minSuf(n);
    vi bad;
    minSuf[n-1] = a[n-1];
    REPR(i, n-2, 0) minSuf[i] = min(minSuf[i+1], a[i]);
    FOR(i, n) {
        if (a[i] <= minSuf[i]) ans.push_back(a[i]);
        else bad.push_back(a[i] + 1);
    }
    sort(ALL(bad));
    if (SZ(ans) && SZ(bad) && ans.back() > bad.front()) {
        bad.push_back(ans.back() + 1);
        ans.pop_back();
    }
    sort(ALL(bad));
    FORR(x, bad) ans.push_back(x);

    FORR(x, ans) cout << x << " ";
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
