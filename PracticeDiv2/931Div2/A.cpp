#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    int ans = 0;
    ans += abs(nums[0] - nums[n-1]);
    ans += abs(nums[n-1] - nums[1]);
    ans += abs(nums[1] - nums[n-2]);
    ans += abs(nums[n-2] - nums[0]);

    cout << ans << endl;
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
