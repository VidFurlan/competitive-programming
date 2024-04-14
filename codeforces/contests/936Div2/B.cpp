#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }

        long long totalMax = nums[0];
        long long currMax = nums[0];
        for(int i = 1; i < n; i++) {
            currMax = max(static_cast<long long>(nums[i]), currMax + nums[i]);
            totalMax = max(totalMax, currMax);
        }

        if (totalMax > 0) {
            for (int i = 0; i < k; i++) {
                sum += totalMax;
                totalMax = ((totalMax * 2) % MOD);
            }
            sum %= MOD; 
        }

        cout << (sum % MOD + MOD) % MOD << endl; 
    }
}
