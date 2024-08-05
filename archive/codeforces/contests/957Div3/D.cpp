#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<bool> seen(n + 2);
    queue<pii> q;
    q.push({0, 0});
    seen[0] = 1;
    while (!q.empty()) {
        int i = q.front().first;
        int w = q.front().second;
        q.pop();

        if (i == 0 || s[i - 1] == 'L') {
            for (int j = 1; j <= m; j++) {
                if (i + j > n) {
                    cout << "YES" << endl;
                    return;
                }

                if (i + j <= n && s[i + j - 1] != 'C' && !seen[i + j]) {
                    seen[i + j] = 1;
                    q.push({i + j, w});
                }
            }
        }

        if (i > 0 && i <= n && s[i - 1] == 'W' && w < k) {
            if (i >= n) {
                cout << "YES" << endl;
                return;
            }

            if (i < n && s[i] != 'C' && !seen[i + 1]) {
                seen[i + 1] = 1;
                q.push({i + 1, w + 1});
            }
        }
    }
    cout << "NO" << endl;
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
