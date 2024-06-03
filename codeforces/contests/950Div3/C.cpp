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
    int n; cin >> n;
    vector<int> a(n), b(n);
    set<int> s;
    FORR(i, a) cin >> i;
    FORR(i, b) { 
        cin >> i;
        s.insert(i);
    }

    int m; cin >> m;
    vector<int> d(m);
    FORR(i, d) cin >> i;
    map<int, int> need;

    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            need[b[i]]++;

    bool f = 1;
    if (s.find(d.back()) == s.end())
        f = 0;

    for (int i = 0; i < m; i++)
        if (need[d[i]] > 0)
            need[d[i]]--;

    FORR2(x, y, need)
        if (y > 0) {
            cout << "NO" << endl;
            return;
        }

    if (f)
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
