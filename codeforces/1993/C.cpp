#include <bits/stdc++.h>
using namespace std;
#define SINGLE_TEST 0

typedef long long ll;
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
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    FORR(x, a) cin >> x;
    sort(ALL(a));
 
    FOR(i, n-1) {
        if (a[i] + k > a.back()) continue;
        ll x = a.back() - a[i] - k;
        x = (x + 2 * k - 1) / (2 * k);
        a[i] += x * 2 * k;
    }
 
    sort(ALL(a));
    FOR(i, n) a.push_back(a[i] + 2 * k);
    ll ans = LLONG_MAX;
    for (int i = n - 1; i < 2 * n; i++) {
        if (a[i] - a[i - n + 1] >= k) continue;
        ans = min(ans, a[i]);
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
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
