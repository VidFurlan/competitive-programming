#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &num : a)
        cin >> num;

    vector<int> p(n);
    int mex = n;

    for (int i = n - 1; i >= 0; i--) {
        p[i] = mex - a[i];
        mex = min(mex, p[i]);
    }

    for (int num : p)
        cout << num << " ";
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
