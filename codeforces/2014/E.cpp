#include <bits/stdc++.h>
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

template<typename T> constexpr T inf = 0;
template<> constexpr int inf<int> = 1e9;
template<> constexpr ll inf<ll> = 1e18;
template<typename T>
vector<T> dijkstra(int s, vector<vector<pair<int,T>>> adj){
    int n=adj.size();
    vector<T> dis(n, inf<T>);
    vector<int> vis(n);
    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> pq;
    dis[s]=0,pq.push({0,s});
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
    int n, m, h; cin >> n >> m >> h;
    vi horse(n * 2);
    FOR(i, h) {
        int x; cin >> x; x--;
        horse[x] = 1;
    }
    vector<vector<pair<int, ll>>> adj(n * 2);
    FOR(i, m) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        adj[u + n].push_back({v + n, w / 2});
        adj[v + n].push_back({u + n, w / 2});
    }

    FOR(i, n)
        if (horse[i])
            adj[i].push_back({n + i, 0});

    vl dist1 = dijkstra<ll>(0, adj), dist2 = dijkstra<ll>(n - 1, adj);
    ll ans = LLINF;
    FOR(i, n) {
        ans = min(ans, max(min(dist1[i], dist1[i + n]), min(dist2[i], dist2[i + n])));
    }
    cout << (ans > LLINF / 2 ? -1 : ans) << endl;
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
        // cout << "---\n";
    }
#endif

    return 0;
}
