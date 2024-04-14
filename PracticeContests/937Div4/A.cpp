#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a < b && b < c) {
        cout << "STAIR" << endl;
    } else if (a < b && b > c) {
        cout << "PEAK" << endl;
    } else {
        cout << "NONE" << endl;
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
