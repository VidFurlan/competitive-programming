#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int ans = 0, max_i = 0;
    for (int i = 1; i < n; i++) {
        int g = __gcd(n, i);
        if (g + i > ans) {
            ans = g + i;
            max_i = i;
        }
    }
    cout << max_i << endl;
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
