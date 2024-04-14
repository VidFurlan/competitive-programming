#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    string t;
    cin >> t;
    int h = stoi(t.substr(0,2)), m = stoi(t.substr(3, 2));
    string p = (h >= 12) ? " PM\n" : " AM\n";
    h = (h % 12) ? h % 12 : 12;
    cout << (h < 10 ? "0" : "") << h << ':' << (m < 10 ? "0" : "") << m << p;
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
