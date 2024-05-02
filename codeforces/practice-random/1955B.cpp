#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n, c, d; cin >> n >> c >> d;
    map<int, int> s; 
    for (int i = 0; i < n * n; i++) {
        int t; cin >> t;
        s[t]++;
    }
    int mn = (*s.lower_bound(0)).first;

    for (int i = 0; i < n; i++) {
        int f1 = mn + i * c;
        if (s[f1] == 0) {
            cout << "NO" << endl;
            return;
        }
        s[f1]--;

        for (int j = 1; j < n; j++) {
            int f2 = f1 + j * d;
            if (s[f2] == 0) {
                cout << "NO" << endl;
                return;
            }
            s[f2]--;
        }
    }

    cout << "YES" << endl;
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
