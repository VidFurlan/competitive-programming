#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int ans = min(n, 4);
    for (int i = 0; i < n; i++) {
        if (i + 1 == a[a[i] - 1]) {
            cout << 2 << endl;
            return;
        }
        int p1 = a[i];
        int p2 = a[p1 - 1];
        if (a[p1 - 1] == p2) {
            ans = min(ans, 3);
        }
    }
    cout << ans << endl;
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
