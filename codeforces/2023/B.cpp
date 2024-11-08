#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define SINGLE_TEST 0

typedef long long ll;
typedef unsigned long long ull; 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
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

#include <vector>
#include <queue>

template<typename T> constexpr T inf = 0;
template<> constexpr int inf<int> = 1e9;
template<> constexpr long long inf<long long> = 1e18;
template<typename T>
std::vector<T> dijkstra(int s, std::vector<std::vector<std::pair<int,T>>> adj){
    int n=adj.size();
    std::vector<T> dis(n, inf<T>);
    std::vector<int> vis(n);
    std::priority_queue<std::pair<T,int>, std::vector<std::pair<T,int>>, std::greater<std::pair<T,int>>> pq;
    dis[s]=0, pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto &[v,w]: adj[u]) if(d+w<dis[v]){
            dis[v]=d+w;
            pq.push({dis[v],v});
        }
    }
    return dis;
}

void solve() {
    int n; cin >> n;
    vl a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];
    vector<vector<pil>> adj(n);
    REP(i, 1, n-1) adj[i].push_back({i - 1, 0});
    FOR(i, n) {
        if (b[i] > i) {
            adj[i].push_back({b[i] - 1, a[i]});
        }
    }
    vl dist = dijkstra(0, adj);
    ll ans = a[0];
    vl f(n);
    f[0] = a[0];
    FOR(i, n-1) f[i + 1] = f[i] + a[i + 1];
    FOR(i, n) {
        if (dist[i] == inf<ll>) break;
        ans = max(ans, f[i] - dist[i]);
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
