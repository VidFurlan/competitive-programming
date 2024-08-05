#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    FORR(i, a) cin >> i;

    ll ans = 0;
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < i * 2; j++) {
            map<int, int> cnt;
            for (int k = 0; k < n; k++) {
                if (a[k].size() == j) {
                    int sum = 0;
                    for (int l = 0; l < a[k].size(); l++) {
                        sum += (l < i) ? (a[k][l] - '0') : (-a[k][l] + '0');
                    }
                    cnt[sum]++;
                }
            }

            for (int k = 0; k < n; k++) {
                if (j + a[k].size() == i * 2) {
                    int sum = 0;
                    for (int l = 0; l < a[k].size(); l++) {
                        sum += (j + l < i) ? (a[k][l] - '0') : (-a[k][l] + '0');
                    }
                    ans += cnt[-sum];
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
