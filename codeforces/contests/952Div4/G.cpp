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

int sum(int n) {
    string s = to_string(n);
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

ll calc(ll n, ll m) {
    ll ans = 1;
    if (!n) 
        return 0;
    
    while (m > 0) {
        if (m & 1)
            ans = (ans * n) % MOD;
        m >>= 1;
        n = (n * n) % MOD;
    }

    return ans;
}

void solve() {
    ll l, r, k; cin >> l >> r >> k;
    //for (int i = pow(10, l); i < pow(10, r); i++) {
    //    if (sum(i * k) == k * sum(i)) {
    //        ans++;
    //        cout << '\t';
    //    }
    //    cout << "i: " << i << "  i*k: " << i * k << "  sum(i): " << sum(i) << "  sum(i*k): " << sum(i * k) << endl;
    //}
    
    if (k >= 10) {
        cout << 0 << endl;
        return;
    }

    ll m = 10 / k + (10 % k != 0);
    m %= MOD;

    cout << (calc(m, r) - calc(m, l) + MOD) % MOD << endl;
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
