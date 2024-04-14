#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

// https://www.youtube.com/watch?v=2x4ioToqe_c
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    
    vector<int> v(x);
    for (int &i : v) 
        cin >> i;
    
    sort(v.begin(), v.end());

    int ans = x - 2;
    for (int i = 0; i < x - 1; i++) {
        if (v[i] + 2 == v[i+1])
            ans++;
    }

    if ((v[x-1] + 2) % n == v[0])
        ans++;
    
    cout << ans << '\n';
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
