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
	vl dCnt(100);
	dCnt[1] = 9;
	ll cur = 10;
	ll dig = 2;
	ll prev = 9;
	while (cur <= LLINF) {
		dCnt[dig] = 9 * dig * cur;
		prev += dCnt[dig];
		dig++;
		cur *= 10;
	} 
	while (n--) {
		ll q; cin >> q; 
		if (q < 10) {
			cout << q << endl;
			continue;
		}
		ll digs = 1;	
		ll cnt = 9;
		while (cnt < q) cnt += dCnt[++digs];
		q -= cnt - dCnt[digs] + 1;
		//debug(q);
		//cout << digs << endl;
		ll base = q / digs;
		ll num = base + powl(10ll, digs-1);
		cout << to_string(num)[q % digs] << endl;
		//debug(num);
	}
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
