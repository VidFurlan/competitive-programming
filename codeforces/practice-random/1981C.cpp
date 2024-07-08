#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <ostream>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), ans(n + 2);
    bool f = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
        if (a[i] != -1) {
            f = 1;
            ans[i] = a[i];
        }
        else {
            ans[i] = ans[i - 1] / 2;
        }

        if (f && ans[i] == 0) {
            ans[i] = 2;
        }
    }
    
    ans.back() = 0;

    for (int i = n; i >= 1; i--) {
        if (a[i] == -1) {
            ans[i] = max(ans[i], ans[i + 1] / 2);
        }
        if (ans[i] == 0) {
            ans[i] = 2;
        }
    }

    for (int i = 1; i < n; i++) {
        if (ans[i] != ans[i + 1] / 2 && ans[i] / 2 != ans[i + 1]) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
        // cout << "-------------------\n";
    }

    return 0;
}
