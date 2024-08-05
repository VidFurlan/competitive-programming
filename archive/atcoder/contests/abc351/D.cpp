#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void dfs(vector<vector<int>> &g, int i, int j, int &ans, int &n, int &w, int &h) {
    if (i < 0 || j < 0 || i >= h || j >= w)
        return;

    if (g[i][j] == -1 || g[i][j] == -n || g[i][j] == n)
        return;
    
    if (g[i][j] < -1 && g[i][j] != -n) {
        ans++;
        g[i][j] = -n;
        return;
    }
    
    ans++;
    g[i][j] = n;
    dfs(g, i - 1, j, ans, n, w, h);
    dfs(g, i + 1, j, ans, n, w, h);
    dfs(g, i, j - 1, ans, n, w, h);
    dfs(g, i, j + 1, ans, n, w, h);
}

void solve() {
    int h, w; 
    cin >> h >> w;
    vector<string> in(h);
    for (string &s : in)
        cin >> s;

    vector<vector<int>> g(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (in[i][j] != '#')
                continue;
            g[i][j] = -1;
            if (i - 1 >= 0 && in[i - 1][j] != '#')
                g[i - 1][j] = -2;
            if (i + 1 < h && in[i + 1][j] != '#')
                g[i + 1][j] = -2;
            if (j - 1 >= 0 && in[i][j - 1] != '#')
                g[i][j - 1] = -2;
            if (j + 1 < w && in[i][j + 1] != '#')
                g[i][j + 1] = -2;
        }

    int ans = 1, n = 2;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (g[i][j] != 0)
                continue;
            n++;
            int c = 0;
            dfs(g, i, j, c, n, w, h);
            ans = max(ans, c);

            // for (auto &r : g) {
            //     for (int i : r)
            //         cout << i << '\t';
            //     cout << endl;
            // }
            // cout << c << endl;
        }


    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
