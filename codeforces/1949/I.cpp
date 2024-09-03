#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define SINGLE_TEST 1
 
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
 
void solve() {
    ll n; cin >> n;
    vvl a(n, vl(3));
    FOR(i, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
    vector<set<ll>> adj(n);
     
    function<bool(ll, ll)> compare = [&](ll i, ll j) {
        ll c = (a[i][2] + a[j][2]);
        ll w = max(a[i][0], a[j][0]) - min(a[i][0], a[j][0]);
        ll h = max(a[i][1], a[j][1]) - min(a[i][1], a[j][1]);
        return (w * w + h * h <= c * c);
    };
 
    FOR(i, n) {
        REP(j, i + 1, n - 1) {
            if (compare(i, j)) {
                adj[i].insert(j);
                adj[j].insert(i);
                // cout << i << " - " << j << endl;
            }
        }
    }
    
    vector<bool> seen(n);
    vector<bool> odd(n);
    ll sz[] = {0, 0};
    bool f = 1;
 
    function<void(ll, ll)>dfs = [&](ll v, ll par) {
        if (seen[v]) return;
        seen[v] = 1;
        
        odd[v] = odd[par] ^ 1;
        sz[odd[v]]++;
 
        for(ll u : adj[v]) {
            if (par == u) continue;
            dfs(u, v);
            if (odd[u] == odd[v]) {
                f = 0;
                break;
            }
        }
    };
    
    FOR(i, n) {
        if (seen[i]) continue;

        sz[0] = sz[1] = 0;
        f = 1;

        dfs(i, i);
        if (f && sz[0] != sz[1]) {
            cout << "YES" << endl;
            return;
        }
    }
    
    cout << "NO" << endl;
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
