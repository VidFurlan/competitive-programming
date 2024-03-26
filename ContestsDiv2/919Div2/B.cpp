#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main () {
    int k;
    for (cin >> k; k > 0; k--) {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> nums (n, 0);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        sort(nums.begin(), nums.end());

        for (int i = nums.size() - 1; i > 0 && k > 0; k--, i--)
            nums.pop_back();
        for (int i = nums.size() - 1; i > 0 && x > 0; x--, i--)
            nums[i] = -nums[i];

        int ans = 0;
        for (int num : nums) 
            ans += num;
        cout << "->" << ans << '\n';
    }
}
