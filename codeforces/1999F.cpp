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

const int MAXN = 70005;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

void factorial() {
	fac[0] = 1;
	for (ll i = 1; i <= MAXN; i++) { fac[i] = (fac[i - 1] % MOD) * i % MOD; }
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (ll i = MAXN; i >= 1; i--) { inv[i - 1] = (inv[i] % MOD) * i % MOD; }
}

ll choose(ll n, ll r) { return (fac[n] % MOD) * inv[r] % MOD * inv[n - r] % MOD; }

void solve() {
    ll n, k; cin >> n >> k;
    vi a(n);
    FORR(x, a) cin >> x;
    ll one = count(ALL(a), 1);
    ll ans = 0;
    for (ll i = (k-1)/2; i >= 0; i--) {
        if (k - i > one || i > n - one) continue;
        ans += ((choose(one, k - i) % MOD) * (choose(n - one, i) % MOD)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#if SINGLE_TEST
    solve();
#else
    factorial();
    inverses();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
#endif

    return 0;
}
