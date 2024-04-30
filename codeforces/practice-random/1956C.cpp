#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

vector<int> dp(501);
void calc(int n) {
    for (int i = 1; i < n; i++)
        dp[i] = dp[i - 1] + i * i + (i - 1) * i;
}

void solve() {
    int n; cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        s += to_string(i);
        s += " ";
    }
    cout << dp[n] << " " << 2 * n << endl;
    for (int i = 0; i < n; i++) {
        cout << "1 " << n - i << " " << s << endl;
        cout << "2 " << n - i << " " << s << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    calc(501);

    while (t--) {
        solve();
    }

    return 0;
}
