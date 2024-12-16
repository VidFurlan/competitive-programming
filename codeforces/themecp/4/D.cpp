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

const ll MOD9 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

const int MAXN = 1e6;
const int MODC = MOD9;
long long fac[MAXN + 1];
long long inv[MAXN + 1];
long long exp(long long x, long long n, long long m) {
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fac[i] = fac[i - 1] * i % MODC;
    }
}

void inverses() {
    inv[MAXN] = exp(fac[MAXN], MODC - 2, MODC);
    for (int i = MAXN; i >= 1; i--) {
        inv[i - 1] = inv[i] * i % MODC;
    }
}

long long choose(int n, int r) { return fac[n] * inv[r] % MODC * inv[n - r] % MODC; }

pll calc(int n) {
    if (n == 2) return {1, 0};
    pll c = calc(n - 2);
    return {(choose(n - 1, n / 2) % MOD9 + c.se % MOD9) % MOD9, (choose(n - 2, n / 2) % MOD9 + c.fi % MOD9) % MOD9};
}

void solve() {
    ll n; cin >> n;
    ll tot = choose(n, n / 2);
    pll a = calc(n);
    cout << a.fi << " " << a.se << " 1" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial();
	inverses();

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
