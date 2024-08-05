#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n, c, k; cin >> n >> c >> k;
    string s; cin >> s;

    vector<vector<char>> mask(c, vector<char>(n));
    for (int i = 0; i < c; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[j] - 'A' == i) {
                for (int l = 0; l < k && j - l >= 0; l++) {
                    mask[i][j - l] = 1;
                }
            }
        }
    }

    FORR(i, mask) {
        FORR(j, i) {
            cout << (char)(j + '0');
        }
        cout << endl;
    }
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
