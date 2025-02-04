#include <iostream>
#include <vector>
#include <algorithm>
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
    vl a(n);
    FOR(i, n) cin >> a[i];
    sort(ALL(a));
    int l = 0, r = n-1;
    ll x = 0;
    ll ans = 0;
    while (l < r) {
        if (x < a[r]) {
            ll need = a[r] - x;
            ll diff = max(0ll, a[l] - need);
            ll cont = a[l] - diff;
            a[l] = diff;
            x += cont;
            ans += cont;
        }
        if (x == a[r]) {
            a[r] = 0;
            x = 0;
            ans++;
        }

        if (a[l] == 0) l++;
        if (a[r] == 0) r--;
    }
    if (l == r) {
        if (x <= a[r] && x != 0) {
            a[r] -= x;
            x = 0;
            ans++;
            ans += a[r] / 2 + (a[r] % 2);
        }
        else if (x == 0) {
            ans += min(a[r] / 2 + 1 + (a[r] % 2), a[r]);
        }
        else {
            ans += a[r];
        }
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
