#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n), b(n);
    FORR(i, a) { 
        cin >> i;
        FORR(c, i) c -= '0';
    }
    
    FORR(i, b) { 
        cin >> i;
        FORR(c, i) c -= '0';
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            while (a[i][j] != b[i][j]) {
                a[i][j] = (a[i][j] + 1) % 3;
                a[i + 1][j + 1] = (a[i + 1][j + 1] + 1) % 3;

                a[i + 1][j] = (a[i + 1][j] + 2) % 3;
                a[i][j + 1] = (a[i][j + 1] + 2) % 3;
            }
        }
    }

    if (a == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
