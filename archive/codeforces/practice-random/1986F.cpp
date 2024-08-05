#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

vector<set<ll>> adj;
vector<ll> vis, tin, low, f, sum;
ll timer;
ll n, m;
vector<pll> dp;

void tarjanDfs(ll node, ll p) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    sum[node] = 1;

    FORR(v, adj[node]) {
        if (v == p) continue;
        if (vis[v]) {
            low[node] = min(low[node], tin[v]);
        } 
        else {
            tarjanDfs(v, node);
            sum[node] += sum[v];
            low[node] = min(low[node], low[v]);
            if (low[v] > tin[node]) {
                dp.push_back({node, v});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    dp = vector<pll>();
    adj = vector<set<ll>>(n + 2);
    vis = tin = low = f = sum = vector<ll>(n + 2);

    FOR(i, m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    FOR(i, n) {
        if (!vis[i]) {
            tarjanDfs(i, i);
        }
    }

    ll ans = n * (n - 1) / 2;
    FORR(i, dp) {
        if (f[i.first] != i.second) swap(i.first, i.second);
        ans = min(ans, sum[i.first] * (sum[i.first] - 1) / 2 + (n - sum[i.first]) * (n - sum[i.first] - 1) / 2);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
