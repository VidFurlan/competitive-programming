#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
#define SINGLE_TEST 0

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define REP(i, k, n) for (int(i) = (k); (i) <= (n); ++(i))
#define REPR(i, k, n) for (int(i) = (k); (i) >= (n); --(i))
#define FORR(x, arr) for (auto &x : arr)
#define FORR2(x, y, arr) for (auto &[x, y] : arr)
#define ALL(a) (a.begin()), (a.end())
#define RALL(a) (a.rbegin()), (a.rend())
#define REVERSE(v) reverse(ALL(v))
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = INF;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    vvi cnt(2, vi(26));
    FOR(i, (n % 2 == 0 ? n : n - 1)) {
        cnt[i % 2][s[i] - 'a']++;
    }
    
    if (n % 2 == 0) {
        ans = n - *max_element(ALL(cnt[0])) - *max_element(ALL(cnt[1]));
    }
    else {
        ans = n - 1 - *max_element(ALL(cnt[0])) - *max_element(ALL(cnt[1]));
        //cout << "->" << ans << endl;
        //cout << *max_element(ALL(cnt[0])) << " " << *max_element(ALL(cnt[1])) << endl;

        vvi suff(2, vi(26));
        REPR(i, n - 2, 0) {
            cnt[i % 2][s[i] - 'a']--;
            suff[i % 2][s[i + 1] - 'a']++;

            vvi sum = cnt;
            FOR(i, 26) {
                sum[0][i] += suff[0][i];
                sum[1][i] += suff[1][i];
            }

            ans = min(ans, n - 1 - *max_element(ALL(sum[0])) - *max_element(ALL(sum[1])));
        }

        ans++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#if SINGLE_TEST
    solve();
#else
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
#endif

    return 0;
}
