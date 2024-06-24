#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

ll calc(map<ll, ll> &mp, ll k) {
    if (mp.empty()) return 0;
    if (mp.size() == 1) return 0;

    ll ans = 0;
    if (mp.size() % 2 == 1) {
        vector<ll> v;
        FORR2(i, j, mp) v.push_back(i);
        vector<ll> prefix(v.size()), suffix(v.size());

        prefix[1] = v[1] - v[0];
        suffix[v.size() - 2] = v[v.size() - 1] - v[v.size() - 2];

        for (int i = 3; i < v.size(); i++)
            prefix[i] = prefix[i - 2] + v[i] - v[i - 1];

        for (int i = v.size() - 4; i >= 0; i--)
            suffix[i] = suffix[i + 2] + v[i + 1] - v[i];

        ll mn = LLONG_MAX;
        for (int i = 0; i < v.size(); i += 2) {
            ll sum = 0;
            if (i > 0) sum += prefix[i - 1];
            if (i < v.size() - 1) sum += suffix[i + 1];
            mn = min(mn, sum);
        }
    
        return mn / k;
    }
    
    while (!mp.empty()) {
        ll front1 = (*mp.begin()).first;
        mp.erase(front1);
        ll front2 = (*mp.begin()).first;
        mp.erase(front2);
        ans += abs(front1 - front2) / k;
    }

    return ans;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    FORR(i, a) cin >> i;
    map<ll, map<ll, ll>> mp;

    FORR(i, a) {
        mp[i % k][i] = (mp[i % k][i] + 1) % 2;
        if (mp[i % k][i] == 0) mp[i % k].erase(i);
    }

    // FORR2(i, j, mp) {
    //     cout << i << ": ";
    //     FORR2(x, y, j) cout << x << " ";
    //     cout << endl;
    // }

    ll ans = 0;
    bool f = 0;
    FORR2(i, j, mp) {
        if (j.empty()) continue;
        if (j.size() % 2 == 1) {
            if (f) {
                cout << -1 << endl;
                return;
            }
            f = 1;
        }
        ans += calc(j, k);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
        // cout << "-------------------\n";
    }

    return 0;
}
