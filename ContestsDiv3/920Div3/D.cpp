#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums_a (n);
        vector<int> nums_b (m);

        for (int i = 0; i < n; i++)
            cin >> nums_a[i];
        for (int i = 0; i < m; i++)
            cin >> nums_b[i];

        sort(nums_a.begin(), nums_a.end());
        sort(nums_b.begin(), nums_b.end());

        cout << endl;
        for (auto a : nums_a)
            cout << a << " ";
        cout << endl;
        for (auto a : nums_b)
            cout << a << " ";
        cout << endl;

        int l = 0, r = m - 1, ans = 0;
        for (int i = 0; i < nums_a.size(); i++) {
            cout << nums_a[i] << " - " << nums_b[l] <<  " / " << nums_b[l] << " l: " << l  << " r: " << r << "     |" << abs(nums_a[i] - nums_b[l]) << "|" << abs(nums_a[i] - nums_b[r]) << "|\n";
            if (abs(nums_a[i] - nums_b[l]) < abs(nums_a[i] - nums_b[r])) {
                ans += abs(nums_a[i] - nums_b[r]);
                r--;
            }
            else {
                ans += abs(nums_a[i] - nums_b[l]);
                l++;
            }
        }

        cout << ans << '\n';
    }
}

