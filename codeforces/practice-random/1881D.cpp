#include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) 
        cin >> i;
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int p = a[i] + i + 1, dp_i;
        
        if (p > n)
            dp_i = n + 1;
        else if (p == n)
            dp_i = 0;
        else 
            dp_i = dp[p];

        dp[i] = min(dp[i + 1] + 1, dp_i); 
    }

    cout << dp[0] << endl;
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
