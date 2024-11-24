#include <algorithm>
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
    ll x, m; cin >> x >> m;
    ll ans = 0;
    for (ll y = 1; y <= min(x, m); y++) {
        ans += (x ^ y) % y == 0;
    }
    ll l = 2ll, h = m / x;
    ll k = 0;
    while (l <= h) {
        ll mid = (l + h) / 2;
        ll z = x * mid; 
        ll y = z ^ x;
        if (y <= m) {
            k = mid - 1;
            l = mid + 1;
        } 
        else {
            h = mid - 1;
        }
    }
	for(ll i=max(2LL,k+2);i<(k+10);i++){
		ll mult = x*i;
		ll y = mult^x;
		if(y<=m)ans++;
	}
    cout << ans + k << endl;
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
