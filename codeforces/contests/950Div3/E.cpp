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
    vector<vector<int>> mat1(n, vector<int>(m)), mat2(n, vector<int>(m));
    FORR(i, mat1) FORR(j, i) cin >> j;
    FORR(i, mat2) FORR(j, i) cin >> j;
    
    set<set<int>> st;
    FORR(i, mat1) st.insert(set<int>(ALL(i)));
    FORR(i, mat2)
        if (st.find(set<int>(ALL(i))) == st.end()) {
            cout << "NO" << endl;
            return;
        }
    
    st.clear();
    FOR(j, m) {
        set<int> s;
        FOR(i, n) 
            s.insert(mat1[i][j]);
        st.insert(s);
    }

    FOR(j, m) {
        set<int> s;
        FOR(i, n) 
            s.insert(mat2[i][j]);
        if (st.find(s) == st.end()) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
