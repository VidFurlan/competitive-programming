#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;

    set<char> st, st_cpy; 
    for (int i = 'a'; i < 'a' + k; i++) st.insert(i);
    st_cpy = st;

    string ans;
    for (int i = 0; i < m && ans.size() < n; i++) {
        char c = s[i];
        st.erase(c);
        if (st.size() == 0) {
            ans += c;
            st = st_cpy;
        }
    }

    if (ans.size() < n) {
        cout << "NO\n";
        for (char c : st)
            while (ans.size() < n)
                ans += c;    
        cout << ans << endl;
    }
    else
        cout << "YES\n";
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
