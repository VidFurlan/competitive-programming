#include <bits/stdc++.h>
#include <cmath>
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

int n, m, num; 
vi cnt;
vector<vector<int>> mp;
vector<string> a;

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '.' || mp[i][j] != 0) return;

    mp[i][j] = num;
    cnt[num]++;

    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}
 
void solve() {
    cin >> n >> m;
    cnt = {0};
    mp = vector<vector<int>>(n, vector<int>(m, 0));
    num = 0;

    a = vector<string>(n);
    FORR(i, a) cin >> i;

    FOR(i, n)
        FOR(j, m) {
            if (a[i][j] == '#' && mp[i][j] == 0) { 
                num++; 
                cnt.push_back(0); 
            }
            dfs(i, j);
        }
 
    int ans = 0;
    FOR(i, n) {
        set<int> st;
        int sum = 0;
        FOR(j, m) {
            st.insert(mp[i][j]);
            if (i > 0)
                st.insert(mp[i - 1][j]);
            if (i < n - 1)
                st.insert(mp[i + 1][j]);
            if (mp[i][j] == 0)
                sum++;
        }
        FORR(j, st)
            sum += cnt[j];
        ans = max(ans, sum);
    }
 
    FOR(j, m) {
        set<int> st;
        int sum = 0;
        FOR(i, n) {
            st.insert(mp[i][j]);
            if (j > 0)
                st.insert(mp[i][j - 1]);
            if (j < m - 1)
                st.insert(mp[i][j + 1]);
            if (mp[i][j] == 0)
                sum++;
        }
        FORR(j, st)
            sum += cnt[j];
        ans = max(ans, sum);
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
