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
	vl a(n);
	FOR(i, n) cin >> a[i];
	ll l = 0, h = INF+10;
	ll ans = 1;
	while (l < h) {
		ll mid = (l + h) / 2;
		bool ok = 1;
		vl cur = a;
		REPR(i, n-1, 2) {
			if (cur[i] < mid) { ok = 0; break; }
			ll extra = min(a[i], cur[i] - mid) / 3;
			cur[i-1] += extra;
			cur[i-2] += 2*extra;
		}
		if (min(cur[0], cur[1]) < mid) ok = 0;
		if (ok) {
			ans = max(ans, mid);
			l = mid+1;
		}
		else {
			h = mid;
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
