#include <bits/stdc++.h>
#include <functional>
#include <queue>
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
    int n, a, b; cin >> n >> a >> b;
    vvi adj(n);
    FOR(i, n) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi seen(n), tin(n, -1), low(n, -1);
    int t = 0;

    map<int, int> bridges;

    auto dfs = [&](int v, int p, auto dfs) -> void {
        seen[v] = true;
        tin[v] = low[v] = t++;
        bool pSkip = false;
        for (int to : adj[v]) {
            if (to == p && !pSkip) {
                pSkip = 1;
                continue;
            }
            if (seen[to]) {
                low[v] = min(low[v], tin[to]);
            } 
            else {
                dfs(to, v, dfs);
                low[v] = min(low[v], low[to]);
                if (low[to] > tin[v]) {
                    bridges[v]++;
                    bridges[to]++;
                }
            }
        }
    };

    FOR(i, n) {
        if (!seen[i]) dfs(i, -1, dfs);
    }

    //FORR2(x, y, bridges) cout << x+1 << ": " << y << endl; cout << endl;
    vi safe(n, 1);
    FOR(i, n) {
        if (SZ(adj[i]) == bridges[i]) {
            safe[i] = 0;
        }
    }
    //FOR(i, n) cout << i+1 << ": " << safe[i] << endl; cout << endl;

    auto dijksra = [&](int start) -> vi {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vi dist(n, INF);
        dist[start] = 0;
        pq.push({0, start});
        while (SZ(pq)) {
            auto [d, v] = pq.top(); pq.pop();
            if (d != dist[v]) continue;
            FORR(u, adj[v]) {
                if (d + 1 < dist[u]) {
                    dist[u] = d + 1;
                    pq.push({d + 1, u});
                }
            }
        }
        return dist;
    };

    a--, b--;
    vi distA = dijksra(a), distB = dijksra(b);
    FOR(i, n) {
        if (!safe[i]) continue;
        if (distA[i] > distB[i]) {
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
