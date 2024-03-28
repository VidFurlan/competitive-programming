    #include <algorithm>
    #include <bits/stdc++.h>
    #include <unordered_map>
    #include <vector>
    using namespace std;
     
    int main () {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<long long> nums(n + 1);
            unordered_map<long long, long long> map;
            for (int i = 1; i <= n; i++) {
                cin >> nums[i];
                map[nums[i]]++;
            }
     
            sort(nums.begin() + 1, nums.end());
            
            long long ans = 0;
            for (int i = (n + 1) / 2 ; i <= n; i++) {
                if (nums[i] == nums[(n + 1) / 2]) 
                    ans++;
                else 
                    break;
            }
            cout << ans << endl;
        }
    }
