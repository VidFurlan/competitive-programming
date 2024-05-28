#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

// Solution:
// (a + b) % (b * gcd(a, b)) = 0
// (b * (a/b + 1)) % (b * gcd(a, b)) = 0        Cancle out the b
// (a/b + 1) % gcd(a, b) = 0                    a % b = 0 => gcd(a, b) = b since a multiple of b
// (a/b + 1) % b = 0                            Final simplification that can be brute forced

void solve() {
    int n, m; cin >> n >> m;
    int ans = 0;
    for(int b = 1; b <= m ; b++) {
        for(int a = b; a <= n; a += b) {
            if(a % b == 0 && (a / b + 1) % b == 0) {
                //cout << a << " " << b << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
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
