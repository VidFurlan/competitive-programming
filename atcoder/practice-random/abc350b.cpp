#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n, q; cin >> n >> q;
    vector<bool> t(n, 1);
    for (int i = 0; i < q; i++) {
        int j; cin >> j;
        t[j - 1] = !t[j - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (t[i]) 
            ans++;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
