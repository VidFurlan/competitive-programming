#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;

    string r1, r2;
    for (int i = 0; i < n; i++) {
        r1 += (i % 2 == 0) ? "##" : "..";
        r2 += (i % 2 == 1) ? "##" : "..";
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            cout << r1 << endl << r1 << endl;
        else
            cout << r2 << endl << r2 << endl;
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
