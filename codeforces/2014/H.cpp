#include <iostream>
#include <ostream>
#include <random>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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
    int n, q; cin >> n >> q;
    vector<ull> a(n);
    FOR(i, n) cin >> a[i];
    random_device rd;
    mt19937 gen(rd());
    map<ull, ull> mp;
    set<ull> st;
    FORR(x, a) {
        if (mp.find(x) == mp.end()) {
            do {
                mp[x] = gen();
            } while (st.find(mp[x]) != st.end());
            st.insert(mp[x]);
        }
        x = mp[x];
    }

    vector<ull> f(n+1);
    REP(i, 1, n) f[i] = f[i-1] ^ a[i-1];

    while (q--) {
        int l, r; cin >> l >> r;
        if (f[r] ^ f[l-1]) 
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;
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
