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
			

template <typename T> class LazySegtree {

  private:

	const int sz;

	vector<T> tree;

	vector<T> lazy;


	/** applies lazy update to tree[v], places update at lazy[v] */

	void apply(int v, int len, T add) {

		tree[v] += add * len;

		lazy[v] += add;
	}

	/** pushes down lazy updates to children of v */
	void push_down(int v, int l, int r) {
		int m = (l + r) / 2;
		apply(2 * v, m - l + 1, lazy[v]);
		apply(2 * v + 1, r - m, lazy[v]);
		lazy[v] = 0;
	}

	void range_add(int v, int l, int r, int ql, int qr, int add) {
		if (qr < l || ql > r) { return; }
		if (ql <= l && r <= qr) {
			apply(v, r - l + 1, add);
		} else {
			push_down(v, l, r);
			int m = (l + r) / 2;
			range_add(2 * v, l, m, ql, qr, add);
			range_add(2 * v + 1, m + 1, r, ql, qr, add);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}

	T range_sum(int v, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) { return 0; }
		if (ql <= l && r <= qr) { return tree[v]; }
		push_down(v, l, r);
		int m = (l + r) / 2;
		return range_sum(2 * v, l, m, ql, qr) + range_sum(2 * v + 1, m + 1, r, ql, qr);
	}

  public:
	LazySegtree(int n) : sz(n), tree(4 * n), lazy(4 * n) {}

	/** adds to every value on the range [ql, qr] */
	void range_add(int ql, int qr, int add) { range_add(1, 0, sz - 1, ql, qr, add); }

	/** @return sum of values on [ql, qr] */
	T range_sum(int ql, int qr) { return range_sum(1, 0, sz - 1, ql, qr); }
};

void solve() {

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
