#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; cin >> n;
    vector<vector<int>> c(n, vector<int>(3));

    for (int i = 0; i < n; c[i++][2] = i + 1) 
        cin >> c[i][0] >> c[i][1];
    sort(c.begin(), c.end());

    vector<int> ans;
    vector<int> pmin(n + 1, INT_MAX);
    for (int i = n - 1; i >= 0; i--) {
        pmin[i] = min(pmin[i + 1], c[i][1]);
    }

    for (int i = 0; i < n; i++) {
        bool f = 0;
        // cout << pmin[i] << ": " << c[i][0] << " " << c[i][1] << " " << c[i][2] << endl;
        if (pmin[i] >= c[i][1]) 
            ans.push_back(c[i][2]);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i : ans)
        cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
