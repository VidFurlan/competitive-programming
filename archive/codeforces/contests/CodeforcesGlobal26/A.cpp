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
    int n; cin >> n;
    vector<int> a(n);
    FORR(i, a) cin >> i;
    if (a.front() == a.back()) {
        cout << "NO" << endl;
        return;
    }
    int i = 0;
    bool f = 0;
    for (; i < n - 1; i++) {
        if (a[i] - a.front() != a[i + 1] - a.back()) {
            f = 1;
            break;
        }
    }
    
    if (f == 0) cout << "NO" << endl;
    else cout << "YES" << endl;

    for (int j = 0; j <= i; j++) {
        cout << "R";
    }
    for (; i < n - 1; i++) {
        cout << "B";
    }

    cout << endl;
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
