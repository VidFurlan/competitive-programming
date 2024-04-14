#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; 
    cin >> n;
    vector<int> nums(n);
    for (int &num : nums)
        cin >> num;

    for (int i = 1; i < 10000000; i++) {
        set<int> m;
        for (int j = 0; j < n && m.size() <= 2; j++)
            m.insert(nums[i]);
        
        if (m.size() == 2) {
            cout << i << endl;
            return;
        }
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
