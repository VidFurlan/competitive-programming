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
    ll n; cin >> n;
    vector<ll> a(n);
    bool odd = 1, even = 1;
    ll mx = 0, mxEven = 0;
    FORR(x, a) {
        cin >> x;
        if (x % 2 == 0) {
            odd = 0;
            mxEven = max(mxEven, x);
        }
        else { 
            even = 0;
            mx = max(mx, x);
        }
    }

    if (odd || even) {
        cout << 0 << endl;
        return;
    }

    sort(ALL(a));
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 1) continue;
        if (a[i] <= mx && a[i] % 2 == 0) { 
            ans++; 
            mx += a[i];
            continue; 
        }

        mx += mxEven;
        ans += 2;
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
