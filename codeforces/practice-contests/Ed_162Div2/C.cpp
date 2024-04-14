#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using llp = pair<ll, ll>;
using iip = pair<int, int>;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<llp> subarrs(q);
    for (int i = 0; i < q; i++)
        cin >> subarrs[i].first >> subarrs[i].second;

    vector<ll> sum(n+1);
    vector<ll> cnt(n+1);
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + nums[i];
        cnt[i+1] = cnt[i] + ((nums[i] == 1) ? 1 : 0);
    }

    for (llp subarr : subarrs) {
        ll subarr_size = subarr.second - subarr.first + 1;
        ll curr_sum = sum[subarr.second] - sum[subarr.first-1];
        ll curr_cnt = cnt[subarr.second] - cnt[subarr.first-1];

        if (subarr_size <= 1 || curr_cnt + subarr_size > curr_sum)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
