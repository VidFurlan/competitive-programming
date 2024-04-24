#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);
    int m;

    if (n == 1) {
        cout << k << '\n';
        return;
    }

    for (m = 0; pow(2, m + 1) - 1 <= k; m++);
    
    ans[0] = pow(2, m) - 1;

    if (n > 1)
        ans[1] = k - (pow(2, m) - 1);
    for (int &a : ans)
        cout << a << ' ';
    cout << '\n';
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
