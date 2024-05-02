#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] == b[j]) {
            i++;
        }
        j++;
    }

    cout << i << endl;
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
