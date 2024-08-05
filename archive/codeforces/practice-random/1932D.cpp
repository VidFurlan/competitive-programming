#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <string>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; char ts;
    cin >> n >> ts;

    map<char, int> mp;
    map<char, vector<char>> cards;

    for (int i = 0; i < n * 2; i++) {
        string t; cin >> t;
        cards[t[1]].push_back(t[0]);
        mp[t[1]]++;
    }

    bool f = 1;
    for (char t : "CDHS") {
        if (t == ts)
            continue;
        mp[t] = mp[t] % 2;

        if (mp[ts] - mp[t] < 0) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }

        mp[ts] -= mp[t];
        mp[t] = 0;
    }
    
    for (auto &v : cards)
        sort(v.second.begin(), v.second.end(), greater<int>());

    for (char t : "CDHS") {
        if (t == ts)
            continue;
        while (cards[t].size() > 1) {
            cout << cards[t].back() << t << " ";
            cards[t].pop_back();
            cout << cards[t].back() << t << "\n";
            cards[t].pop_back();
        }
        if (cards[t].size() == 1) {
            cout << cards[t].back() << t << " ";
            cards[t].pop_back();
            cout << cards[ts].back() << ts << "\n";
            cards[ts].pop_back();
        }
    }

    while (cards[ts].size() > 0) {
        cout << cards[ts].back() << ts << " ";
        cards[ts].pop_back();
        cout << cards[ts].back() << ts << "\n";
        cards[ts].pop_back();
    }
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
