#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();

    int i = 0;
    for (; i < n - 1; i++) {
        if (a[i] + 1 != a[i + 1]) {
            cout << ((i % 2 == 0) ? "Alice" : "Bob") << endl;
            return;
        }
    }

    cout << ((i % 2 == 1) ? "Alice" : "Bob") << endl;
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
