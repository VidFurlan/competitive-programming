#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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

void solve() {
    ll n; cin >> n;
    vl a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];
    vl pref(n+1);
    FOR(i, n) pref[i+1] = pref[i] + b[i];
    //FORR(x, pref) cout << x << " "; cout << endl;
    vl full(n+1);
    vl extra(n+1);
    REPR(i, n-1, 0) {
        ll have = a[i] + pref[i];
        ll j = distance(pref.begin(), upper_bound(ALL(pref), have)) - 2;
        if (j < i) {
            extra[i] += a[i];
        }
        else {
            full[i]++;
            full[j+1]--;
            extra[j+1] += a[i] - (pref[j+1] - pref[i]);
        }
        //cout << a[i] << ": " << i << " " << j << endl;
        //FORR(x, extra) cout << x << " "; cout << endl;
    }
    FOR(i, n) full[i+1] += full[i];
    //FORR(x, full) cout << x << " "; cout << endl;
    //FORR(x, extra) cout << x << " "; cout << endl;
    FOR(i, n) {
        cout << full[i] * b[i] + extra[i] << " ";
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
