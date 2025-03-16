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
	int n; cin >> n;
	vvi a(n);
	unordered_map<int, vi> adjSk;
	vector<unordered_map<int, int>> adj(n);
	FOR(i, n) {
		int m; cin >> m;		
		a[i] = vi(m);
		FOR(j, m) {
			cin >> a[i][j];
			adjSk[a[i][j]].push_back(i);
		}
	}
	set<pii> s;
	FORR2(sk, v, adjSk) {
		int m = SZ(v);
		FOR(i, m) REP(j, i+1, m-1) {
			adj[v[i]][v[j]]++;
			adj[v[j]][v[i]]++;
			s.insert({v[i], v[j]});
		}
	}
	//FOR(i, n) {
	//	cout << i << ": \n";
	//	FORR2(x, y, adj[i]) cout << '\t' << x << " " << y << endl; 
	//}
	int mx = -1;
	pii ans = {-1, -1};
	FORR(p, s) {
		auto [x, y] = p;
		int cur = SZ(a[x]) + SZ(a[y]) - adj[x][y];
		if (SZ(a[x]) == adj[x][y] || SZ(a[y]) == adj[x][y]) continue;
		if (cur > mx) {
			mx = cur;
			ans = {x+1, y+1};
		}
	}
	if (mx == -1) cout << -1 << endl;
	else cout << ans.fi << " " << ans.se << endl;
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
