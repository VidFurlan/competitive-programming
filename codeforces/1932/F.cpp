#include <bits/stdc++.h>
#include <locale>
#include <vector>
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
    ll n, m; cin >> n >> m;
    vector<pll> cats(m);
    FOR(i, m) cin >> cats[i].fi >> cats[i].se;
    sort(ALL(cats));
    vl dp(n + 1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    map<ll, ll> mp;

    int j = 0;
    ll mx = 0;
    REP(i, 1, n) {
        for (; j < m && cats[j].fi == i; j++) {
            pq.push({cats[j].se, cats[j].fi});
            mp[cats[j].fi]++;
        }

        while (!pq.empty() && pq.top().fi < i) {
            mp[pq.top().se]--;
            if (mp[pq.top().se] == 0) mp.erase(pq.top().se);
            pq.pop();
        }

        mx = max(mx, (ll)(pq.size() + (mp.empty() ? 0 : dp[mp.begin()->first - 1])));
        dp[i] = mx;
    }

    cout << dp.back() << endl;
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
