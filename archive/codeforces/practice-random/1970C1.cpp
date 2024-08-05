#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    int n, t, start; cin >> n >> t;
    map<int, set<int>> graph;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    cin >> start;

    vector<int> tree;
    for (int i = 1; i <= n && !tree.size(); i++)
        if (graph[i].size() == 1)
            tree.push_back(i);

    while (tree.size() != n) {
        int prev = tree.back();
        tree.push_back(*graph[tree.back()].begin());
        graph[tree.back()].erase(prev);
    }

    int pos;
    for (pos = 0; pos < n; pos++)
        if (tree[pos] == start)
            break;

    int l = pos, r = n - pos - 1;
    if ((l && l % 2 == 1) || (r && r % 2 == 1))
        cout << "Ron\n";
    else 
        cout << "Hermione\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
