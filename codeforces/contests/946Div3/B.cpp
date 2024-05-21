#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<char> st;
    for (char c : s)
        st.insert(c);
    vector<char> chs;
    for (char c : st)
        chs.push_back(c);
    sort(chs.begin(), chs.end());

    map<char, char> mp;
    for (int i = 0; i < chs.size(); i++) {
        mp[chs[i]] = chs[chs.size() - 1 - i];
        mp[chs[chs.size() - 1 - i]] = chs[i];
    }

    for (int i = 0; i < n; i++)
        s[i] = mp[s[i]];

    cout << s << endl;
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
