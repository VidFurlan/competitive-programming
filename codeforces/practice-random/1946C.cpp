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

vector<vector<int>> adj;
int w, ans;

int dfs(int node, int parent) {
    int cnt = 1;
    FORR(next, adj[node]) {
        if (next == parent) 
            continue;
        int next_cnt = dfs(next, node);
        if (next_cnt >= w)
            ans++;
        else
            cnt += next_cnt;
    }
    return cnt;
}

void solve() {
    int n, k; cin >> n >> k;
    k++;
    adj = vector<vector<int>>(n);
    FOR(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l = 1, r = n + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        w = m;
        ans = 0;
        if (dfs(0, -1) >= w) ans++;
        if (ans >= k)
            l = m;
        else
            r = m;
    }
    cout << l << endl;
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
