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

    int maxDiff = 0;
    for (int i = 1; i < n; i++) {
        maxDiff = max(maxDiff, nums[i] - nums[i-1]);
    }

    cout <<
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
