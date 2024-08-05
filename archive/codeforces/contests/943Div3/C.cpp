#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> x(n - 1), a(n);
    for (int &i : x) cin >> i;
    a[0] = 500000000;
    
    for (int i = 1; i < n; i++)
        a[i] = x[i - 1] + a[i - 1];

    for (int &i : a)
        cout << i << " ";
    cout << endl;
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
