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

ll modInverse(ll a, ll mod) {
    ll res = 1, p = mod - 2;
    while (p) {
        if (p & 1) res = res * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    vl a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];
    ll ans = 1;
    vl c = a, d = b;
    sort(ALL(c));
    sort(ALL(d));
    FOR(i, n) { 
        ans *= min(c[i], d[i]);
        ans %= MOD9;
    }
    cout << ans << " ";
    //debug(ans);
    while (q--) {
        int o, idx; cin >> o >> idx;
        idx--;
        if (o == 1) {
            auto it = upper_bound(ALL(c), a[idx]);
            int idxCh = it - c.begin() - 1;
            a[idx]++;
            if (c[idxCh] < d[idxCh]) {
                ans = (ans * modInverse(c[idxCh], MOD9)) % MOD9;
                c[idxCh]++;
                ans = (ans * c[idxCh]) % MOD9;
            } 
            else {
                c[idxCh]++;
            }
        } 
        else {
            auto it = upper_bound(ALL(d), b[idx]);
            int idxCh = it - d.begin() - 1;
            b[idx]++;
            if (d[idxCh] < c[idxCh]) {
                ans = (ans * modInverse(d[idxCh], MOD9)) % MOD9;
                d[idxCh]++;
                ans = (ans * d[idxCh]) % MOD9;
            } 
            else {
                d[idxCh]++;
            }
        }        
        //FORR(x, c) cout << x << " "; cout << endl;
        //FORR(x, d) cout << x << " "; cout << endl;
        //debug(ans);
        cout << ans << " ";
    }
    cout << endl;
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
