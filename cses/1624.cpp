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
	const int n = 8;
	vector<string> g(n);
	FORR(x, g) cin >> x;
	vvi cnt(n, vi(n));
	FOR(i, n) FOR(j, n) if (g[i][j] == '*') cnt[i][j] = 1;
	int ans = 0;
	auto paint = [&](int i, int j, int add) {
		FOR(k, n) cnt[i][k] += add;
		FOR(k, n) cnt[k][j] += add;
		cnt[i][j] -= add;
		REP(k, 1, n-1) {
			if (i+k >= n || j+k >= n) break;
			cnt[i+k][j+k] += add;
		}
		REP(k, 1, n-1) {
			if (i-k < 0 || j-k < 0) break;
			cnt[i-k][j-k] += add;
		}
		REP(k, 1, n-1) {
			if (i+k >= n || j-k < 0) break;
			cnt[i+k][j-k] += add;
		}
		REP(k, 1, n-1) {
			if (i-k < 0 || j+k >= n) break;
			cnt[i-k][j+k] += add;
		}
	};

	auto dfs = [&](int i, int j, auto dfs) {
		if (i == n-1) {
			if (cnt[i][j] == 0) ans++; 
			return;
		}
		if (cnt[i][j]) return;
		paint(i, j, 1);
		FOR(nj, n) dfs(i+1, nj, dfs);
		paint(i, j, -1);
	};
	FOR(nj, n) {
		dfs(0, nj, dfs);
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
