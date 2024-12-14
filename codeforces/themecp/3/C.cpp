#include <iostream>
#include <vector>
#include <algorithm>
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
    vl a(n);
    FOR(i, n) cin >> a[i];
    vl pref(n+1);
    FOR(i, n) pref[i+1] = pref[i] + a[i];
    //FORR(x, pref) cout << x << " "; cout << endl;
    auto query = [&](ll l, ll r) {
        ll k = r - l + 1;
        cout << "? " << k << " ";
        FOR(i, k) cout << l + i + 1 << " ";
        cout << endl;
        cout.flush();
        ll in; cin >> in;
        cout.flush();
        return in;
    };
    ll l = 0, r = n-1;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll q = query(l, mid);
        if (q == pref[mid+1] - pref[l]) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
        //cout << l << " " << r << endl;
    }

    cout << "! " << l + 1 << endl;
    cout.flush();
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
