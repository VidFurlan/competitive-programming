#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    string t; cin >> t;
    string s;
    int ans = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'L')
            continue;
        s += t[i];
    }
    for (char c : s) {
        if (c == 'W')
            break;
        ans++;
    }
    s = s.substr(ans);
    while (!s.empty() && s.back() == 'D') {
        s.pop_back();
        ans++;
    }

    vector<pair<int, char>> v;
    for (char c : s) {
        if (v.empty() || v.back().second != c) {
            v.push_back({1, c});
        } 
        else {
            v.back().first++;
        }
    }

    vector<pair<int, char>> v2;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == 'D' && (v[i].first > 2 || v[i].first >= v[i + 1].first)) {
            ans += v[i].first;
            v2.push_back({v[i].first, 'D'});
        }
        else if (v[i].second == 'W') {
            if (!v2.empty() && v2.back().second == 'W')
                v2.back().first += v[i].first;
            else 
                v2.push_back({v[i].first, 'W'});
        }
    }

    for (auto i : v2) {
        if (i.second == 'D')
            continue;
        ans += i.first * 2;
        ans += max(0, i.first - 2);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
