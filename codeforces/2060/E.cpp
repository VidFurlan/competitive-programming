#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <iomanip>
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

// USACO
class DisjointSet {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSet(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }
		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};

void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    DisjointSet dsuG(n);
    vector<pii> f(m1);
    FOR(i, m1) {
        int u, v; cin >> u >> v;
        u--, v--;
        f[i] = {u, v};
    }
    FOR(i, m2) {
        int u, v; cin >> u >> v;
        u--, v--;
        dsuG.unite(u, v);
    }
    vi cG(n);
    FOR(i, n) {
        cG[i] = dsuG.find(i);
    }
    set<int> s;
    FOR(i, n) {
        s.insert(cG[i]);
    }
    int k = SZ(s), cnt = 0;
    DisjointSet dsuF(n);
    FOR(i, m1) {
        auto [u, v] = f[i];
        if (cG[u] != cG[v]) {
            cnt++;
        }
        else {
            dsuF.unite(u, v);
        }
    }
    map<int, set<int>> mp;
    FOR(u, n) {
        int v = cG[u];
        int f = dsuF.find(u);
        mp[v].insert(f);
    }
    ll sum = 0;
    FORR2(k, v, mp) {
        sum += SZ(v);
    }
    cout << cnt + sum - k << endl;
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
