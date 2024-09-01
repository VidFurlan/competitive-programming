#include <bits/stdc++.h>
#include <bitset>
#include <variant>
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

int n, cnt; 
vi a, dp, visited;
string s;
bitset<200005> seen;

void dfs(int i) {
    if (seen[i]) return;
    seen[i] = 1;
    visited.push_back(i);
    cnt += s[i] == '0';
    dfs(a[i]);
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    dp.assign(n + 1, 0);
    seen.reset();
    FOR(i, n) {
        cin >> a[i];
        a[i]--;
    }
    cin >> s;
    FOR(i, n) {
        visited.clear();
        cnt = 0;
        dfs(i);
        FORR(j, visited) dp[j] = cnt;
    }

    FOR(i, n) cout << dp[i] << " ";
    cout << endl;
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
