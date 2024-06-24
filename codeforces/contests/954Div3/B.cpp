#include <algorithm>
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
    vector<vector<int>> mat(n, vector<int>(m));
    FORR(row, mat)
        FORR(cell, row)
            cin >> cell;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<int> v;
            if (i > 0 && mat[i][j] > mat[i-1][j]) v.push_back(mat[i-1][j]);
            else if (i > 0 && mat[i][j] <= mat[i-1][j]) continue;
            if (j > 0 && mat[i][j] > mat[i][j-1]) v.push_back(mat[i][j-1]);
            else if (j > 0 && mat[i][j] <= mat[i][j-1]) continue;
            if (i < n-1 && mat[i][j] > mat[i+1][j]) v.push_back(mat[i+1][j]);
            else if (i < n-1 && mat[i][j] <= mat[i+1][j]) continue;
            if (j < m-1 && mat[i][j] > mat[i][j+1]) v.push_back(mat[i][j+1]);
            else if (j < m-1 && mat[i][j] <= mat[i][j+1]) continue;

            if (v.empty()) continue;
            sort(ALL(v));
            mat[i][j] = v.back();
        }
    }

    FORR(row, mat) {
        FORR(cell, row)
            cout << cell << " ";
        cout << endl;
    }
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
