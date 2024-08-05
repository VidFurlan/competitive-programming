#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), t(n), p(n);
    for (int &i : a) cin >> i;
    for (int &i : t) cin >> i;

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * t[i];

    p[n - 1] = a[n - 1] * ((t[n - 1] == 0) ? 1 : 0);
    for (int i = n - 2; i >= 0; i--) {
        if (i + k - 1 < n) {
            p[i] = p[i + 1] - a[i + k] * ((t[i + k] == 0) ? 1 : 0) + a[i] * ((t[i] == 0) ? 1 : 0);
            // cout << i << ": " << - a[i + k] * ((t[i + k] == 0) ? 1 : 0) << "  +" << a[i] * ((t[i] == 0) ? 1 : 0) << "\n";
        }
        else {
            p[i] = p[i + 1] + a[i] * ((t[i] == 0) ? 1 : 0);
            // cout << i << ": " << "  +" << a[i] * ((t[i] == 0) ? 1 : 0) << "\n";
        }
    }
    
    int m = 0;
    for (int i : p) m = max(m, i);
    cout << ans + m << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
