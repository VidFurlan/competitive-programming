#include <bits/stdc++.h>
using namespace std;
#define SINGLE_TEST 1

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
    ll n; cin >> n;
    vl a(n);
    FOR(i, n) cin >> a[i];
    vl left(n, -1), right(n, -1);
    stack<int> s;

    FOR(i, n) {
        while (SZ(s) && a[s.top()] <= a[i]) {
            s.pop();
        }
        if (SZ(s)) left[i] = s.top();
        s.push(i);
    }

    while (SZ(s)) s.pop();

    REPR(i, n-1, 0) {
        while (SZ(s) && a[s.top()] <= a[i]) {
            s.pop();
        }
        if (SZ(s)) right[i] = s.top();
        s.push(i);
    }

    ll ans = 0;
    FOR(i, n) {
        ans += (left[i] == -1) ? i + 1 : abs(i - left[i]);
        ans += (right[i] == -1) ? n - i : abs(i - right[i]);
    }
    cout << ans << endl;
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
