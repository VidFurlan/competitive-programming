#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; cin >> n;
    vector<pair<string, int>> a(n);
    for (auto &i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end());
    int sum = 0;
    for (auto i : a) sum += i.second;
    for (int i = 0; i < n; i++) 
        if (i == sum % n) {
            cout << a[i].first << endl;
            return;
        }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
