#pragma GCC optimize("O2")
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

#define n 7
string s; 
bool seen[n+2][n+2] = {0};
char op[] = {'L', 'R', 'U', 'D'};
int dirsX[] = {0, 0, -1, 1};
int dirsY[] = {-1, 1, 0, 0};
int cnt = 0;
void dfs(int i, int j, int ans) {
	if (seen[i][j]) return;
	if ( seen[i-1][j] &&  seen[i+1][j] && !seen[i][j-1] && !seen[i][j+1]) return;
	if (!seen[i-1][j] && !seen[i+1][j] &&  seen[i][j-1] &&  seen[i][j+1]) return;
	if (i == n && j == 1) {
		cnt += ans == n*n-1;
		return;
	}
	seen[i][j] = 1;
	if (s[ans] == 4) FOR(k, 4) dfs(i+dirsX[k], j+dirsY[k], ans+1);
	else dfs(i+dirsX[s[ans]], j+dirsY[s[ans]], ans+1);
	seen[i][j] = 0;
}
void solve() {
	cin >> s;
	FOR(i, 48) {
		if (s[i] == 'L') s[i] = 0;
		else if (s[i] == 'R') s[i] = 1;
		else if (s[i] == 'U') s[i] = 2;
		else if (s[i] == 'D') s[i] = 3;
		else s[i] = 4;
	}
	REP(i, 1, n) {
		seen[i][0] = 1;
		seen[n+1][i] = 1;
		seen[i][n+1] = 1;
		seen[0][i] = 1;
	}
	dfs(1, 1, 0);
	cout << cnt << '\n';
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
