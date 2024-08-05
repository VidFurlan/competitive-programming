#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    FORR(i, a) cin >> i;
    int x = 0, y1 = 0, y2 = 0;
    bool f = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (a[i][j] == '#') {
                x = j;
                y1 = i;
                f = 1;
                break;
            }

        if (f)
            break;
    }

    f = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++)
            if (a[i][j] == '#') {
                x = j;
                y2 = i;
                f = 1;
                break;
            }

        if (f)
            break;
    }

    cout << (y1 + y2) / 2 + 1 << " " << x + 1 << endl;
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
