#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    string a = s, b = t;
    for (int j = 0; j < n - 2; j++)
        if (s[j] == '0' && s[j + 2] == '0')
            b[j + 1] = '1';

    for (int j = 0; j < n - 2; j++)
        if (b[j] == '1' && b[j + 2] == '1')
            a[j + 1] = '1';

    vector<int> psum(n + 1);
    for (int i = 0; i < n; i++)
        psum[i + 1] = psum[i] + a[i] - '0';

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        int sum = psum[r] - psum[l - 1];
        l--, r--;

        if (s[l] == '0' && a[l] == '1') sum--;
        if (l != r && s[r] == '0' && a[r] == '1') sum--;

        if (l + 2 == r) {
            if (a[l + 1] == '1' && s[l + 1] == '0' && (t[l] == '0' || t[r] == '0')) sum--;
        }
        else if (l + 2 < r) {
            if (a[l + 1] == '1' && s[l + 1] == '0' && t[l] == '0') sum--;
            if (a[r - 1] == '1' && s[r - 1] == '0' && t[r] == '0') sum--;
        }

        cout << sum << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        //cout << "-------------------\n";
        solve();
    }

    return 0;
}
