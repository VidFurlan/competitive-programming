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

const int MAXN = 200005;

int fac[MAXN], ifac[MAXN];
 
int bp(int a, int b) {
  if (!b) return 1;
  int r = bp(a, b / 2);
  if (b & 1) return r * 1ll * r % MOD * a % MOD;
  return r * 1ll * r % MOD;
}
 
int ncr(int n, int r) {
  if (n < r) return 0;
  return fac[n] * 1ll * ifac[r] % MOD * ifac[n - r] % MOD;
}

void factorial() {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < MAXN; i++) fac[i] = fac[i - 1] * 1ll * i % MOD, ifac[i] = bp(fac[i], MOD - 2);
}

void solve() {
    ll n, k; cin >> n >> k;
    vi a(n);
    FORR(x, a) cin >> x;
    ll one = count(ALL(a), 1);
    ll ans = 0;
    for (ll i = (k+1)/2; i <= k; i++) {
        ans = (ans + ncr(one, i) * 1ll * ncr(n - one, k - i) % MOD) % MOD;
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
#endif

    return 0;
}
