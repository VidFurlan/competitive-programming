#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

int gcd(int a, int b) { 
    int result = min(a, b); 
    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
  
    return result; 
} 

void solve() {
    int n; cin >> n;
    int ans = 0, max_i = 0;
    for (int i = 1; i < n; i++) {
        if (gcd(n, i) + i > ans) {
            ans = gcd(n, i) + i;
            max_i = i;
        }
    }
    cout << max_i << endl;
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
