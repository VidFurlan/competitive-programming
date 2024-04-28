#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a[t]++;
    }
    
    int mex = 0, f = 0;
    for (; mex <= n; mex++) {
        if (a[mex] == 0)
            break;
        if (a[mex] == 1) {
            if (f)
                break;
            f = 1;
        }
    }
    cout << mex << endl;
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
