#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;

    vector<bool> q(4, false);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > 0)
            q[0] = true;
        else if (x < 0)
            q[2] = true;

        if (y > 0) 
            q[1] = true;
        else if (y < 0)
            q[3] = true;
    }

    if (q[0] + q[1] + q[2] + q[3] == 4)
        cout << "NO\n";
    else
        cout << "YES\n";
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
