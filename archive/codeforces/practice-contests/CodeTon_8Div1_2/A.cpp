#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;

    if (n == k) {
        for (int i = 0; i < n; i++)
            cout << "1 ";
        cout << endl;
    }
    else if (k == 1) {
        cout << n << " ";
        for (int i = 1; i < n; i++)
            cout << i << " ";
        cout << endl;
    }
    else {
        cout << "-1" << endl;
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
