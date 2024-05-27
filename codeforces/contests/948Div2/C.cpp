#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    unordered_set<int> nums;
    FORR(i, a) {
        cin >> i;
        nums.insert(i);
    }
    sort(ALL(a));

    FORR(i, a) {
        if (a.back() % i != 0) {
            cout << n << endl;
            return;
        }
    }

    map<int, int> mp;
    mp[1] = 0;
    for (int i = 0; i < n; i++) {
        map<int, int> nmp = mp;
        FORR2(x, y, mp) {
            int z = x / gcd(x, a[i]) * a[i];
            nmp[z] = max(nmp[z], y + 1);
        }
        mp.swap(nmp);
    }

    int ans = 0;
    FORR2(x, y, mp)
        if (!binary_search(ALL(a), x))
            ans = max(ans, y);

    cout << ans << endl;
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
