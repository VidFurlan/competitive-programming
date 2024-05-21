#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> m;
    for (char c : s)
        m[c]++;
    int v = m['N'] - m['S'], h = m['E'] - m['W'];
    bool f = 0;
    int sum = 0;
    
    for (auto i : m)
        if (i.second > 1) {
            f = 1;
            break;
        } else if (i.second == 1)
            sum++;

    if (sum >= 4)
        f = 1;


    if (v % 2 == 0 && h % 2 == 0 && f) {
        map<char, pii> mvs;
        for (auto i : m) {
            mvs[i.first].first = i.second / 2;
            mvs[i.first].second = i.second / 2;
            if (i.second % 2 == 1)
                mvs[i.first].first++;
        }

        int sum = 0;
        for (auto i : mvs)
            sum += i.second.second;
        if (sum == 0) {
            swap(mvs['E'].first, mvs['E'].second);
            swap(mvs['W'].first, mvs['W'].second);
        }

        for (char c : s) {
            if (mvs[c].first > 0) {
                cout << 'R';
                mvs[c].first--;
            } else {
                cout << 'H';
                mvs[c].second--;
            }
        }
        cout << endl;
    }
    else 
        cout << "NO" << endl;
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
