#include <bits/stdc++.h>
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
    int n; cin >> n;
    map<ll, set<ll>> mp;
    FOR(i, n) {
        ll x; cin >> x;
        mp[i + x].insert(i);
    }
    ll ans = n;
    //while(mp.find(ans) != mp.end()) {
    //    if (mp[ans] == 0) break;
    //    cout << "ans: " << ans << " " << mp[ans] << endl;
    //    ans += mp[ans];
    //}
    set<ll> s = {n};
    while (!s.empty()) {
        set<ll> s2;
        FORR(x, s) {
            FORR(y, mp[x]) {
                if (x + y == x) continue;
                s2.insert(x + y);
                ans = max(ans, x + y);
            }
        }
        s = s2;
    }
    cout << ans << endl;
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
