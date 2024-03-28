#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = n - 1;
    while (a[l] != 1)
        l++;
    while (a[r] != 1)
        r--;

    int ans = r - l + 1;
    while (l <= r) {
        if (a[l] == 1)
            ans--;
        l++;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
