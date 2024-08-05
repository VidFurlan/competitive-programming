#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    set<char> st;
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        st.insert(c);
    }

    ll ans = 0, sz = 0;
    for (int i = 0; i < n; i++) {
        if (sz != 0 && st.find(s[i]) == st.end()) {
            ans += sz * (sz + 1) / 2;
            sz = 0;
        }
        if (st.find(s[i]) != st.end())
            sz++;
    }
    ans += sz * (sz + 1) / 2;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
