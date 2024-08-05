#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(2 * n);
    for (int &i : a) cin >> i;
    
    vector<int> c(n + 1);
    for (int i = 0; i < n; i++)
        c[a[i]]++;

    vector<vector<int>> d(3);
    for (int i = 1; i <= n; i++) 
        d[c[i]].push_back(i);

    vector<int> aa, ab;
    while (aa.size() < 2 * k) {
        if (!d[2].empty()) {
            aa.push_back(d[2].back());
            aa.push_back(d[2].back());
            d[2].pop_back();
            ab.push_back(d[0].back());
            ab.push_back(d[0].back());
            d[0].pop_back();
        } 
        else {
            aa.push_back(d[1].back());
            ab.push_back(d[1].back());
            d[1].pop_back();
        }
    }

    for (int &i : aa) cout << i << " ";
    cout << endl;
    for (int &i : ab) cout << i << " ";
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
