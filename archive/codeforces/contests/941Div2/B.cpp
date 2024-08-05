#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int h, w; cin >> h >> w;
    vector<string> g(h);
    for (auto &s : g)
        cin >> s;
    
    int wh[4] = {0, 0, 0, 0};
    int bl[4] = {0, 0, 0, 0};

    for (int i = 0; i < h; i++) {
        if (g[i].front() == 'W')
            wh[0]++;
        else
            bl[0]++;

        if (g[i].back() == 'W')
            wh[1]++;
        else
            bl[1]++;
    }

    for (int i = 0; i < w; i++) {
        if (g[0][i] == 'W')
            wh[2]++;
        else
            bl[2]++;

        if (g.back()[i] == 'W')
            wh[3]++;
        else
            bl[3]++;
    }

    bool v = 1;
    if (wh[0] && !bl[0] && !wh[1] && bl[1])
        v = 0;
    if (wh[1] && !bl[1] && !wh[0] && bl[0])
        v = 0;
    if (wh[2] && !bl[2] && !wh[3] && bl[3])
        v = 0;
    if (wh[3] && !bl[3] && !wh[2] && bl[2])
        v = 0;

    cout << ((v == 1) ? "YES" : "NO") << endl;
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
