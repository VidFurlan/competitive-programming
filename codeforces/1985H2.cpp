#include <bits/stdc++.h>
#include <cmath>
#include <unordered_set>
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
int maxR, maxC, minR, minC;
vi cnt;
vector<vector<int>> mp;
vector<string> a;

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '.' || mp[i][j] != 0) return;

    mp[i][j] = num;
    cnt[num]++;

    minR = min(minR, i);
    maxR = max(maxR, i);
    minC = min(minC, j);
    maxC = max(maxC, j);

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

    vi rowSum(n), colSum(m);
    vi rowCnt(n), colCnt(m);
    vvi overlap(n, vi(m));
    FOR(i, n)
        FOR(j, m) {
            if (a[i][j] == '.') {
                rowCnt[i]++;
                colCnt[j]++;
            }
            if (a[i][j] == '.' || mp[i][j] != 0) continue;
            if (a[i][j] == '#' && mp[i][j] == 0) { 
                num++; 
                cnt.push_back(0); 
            }

            minR = i;
            maxR = i;
            minC = j;
            maxC = j;

            dfs(i, j);

            REP(k, max(minR - 1, 0), min(maxR + 1, n - 1))
                rowSum[k] += cnt[num];
            REP(k, max(minC - 1, 0), min(maxC + 1, m - 1))
                colSum[k] += cnt[num];

            REP(k, max(minR - 1, 0), min(maxR + 1, n - 1))
                REP(l, max(minC - 1, 0), min(maxC + 1, m - 1))
                    overlap[k][l] += cnt[num];
        }
 
    int ans = 0;
    FOR(i, n) {
        FOR(j, m) {
            int sum = rowSum[i] + colSum[j] - overlap[i][j] + rowCnt[i] + colCnt[j];
            if (a[i][j] == '.') sum--;
            ans = max(ans, sum);
        }
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
