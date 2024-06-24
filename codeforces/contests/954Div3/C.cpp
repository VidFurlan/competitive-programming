#include <bits/stdc++.h>
#include <vector>
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
    string s; cin >> s;
    vector<int> v(m);
    FORR(i, v) cin >> i;
    string c; cin >> c;

    sort(ALL(v));
    sort(ALL(c));

    vector<int> ind;
    for (int i = 0; i < m; i++) {
        if (ind.empty() || v[i] != ind.back())
            ind.push_back(v[i]);
        else if (v[i] == ind.back())
            c.pop_back();
    }
    //cout << ind.size() << " " << c.size() << endl;
    
    for (int i = 0; i < ind.size(); i++)
        s[ind[i] - 1] = c[i];

    cout << s << endl;
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
