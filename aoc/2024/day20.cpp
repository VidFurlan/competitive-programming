#include <bits/stdc++.h>
#include "helper_elf.hpp"
using namespace std;
#define SINGLE_TEST 1

typedef long long ll;
typedef unsigned long long ull; 
typedef long double ld;
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
#define SZ(x) (int)(x).size()
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << (x) << endl

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

const string fileName = "day20.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readStrings();
    int n = SZ(in), m = SZ(in[0]);
    vvl dp(n, vl(m, -1));
    vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int sx = 0, sy = 0, ex = 0, ey = 0;
    FOR(i, n) {
        FOR(j, m) {
            if (in[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (in[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    auto dfs = [&](int x, int y, int d, auto dfs) -> void {
        if (in[x][y] == '#') return;
        if (dp[x][y] != -1) return;
        dp[x][y] = d;
        FOR(i, 4) {
            int nx = x + dirs[i].fi, ny = y + dirs[i].se;
            dfs(nx, ny, d + 1, dfs);
        }
    };
    dfs(sx, sy, 0, dfs);
    //FOR(i, n) {
    //    FOR(j, m) {
    //        cout << setw(3) << dp[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    vector<pii> jumpDirs = {{0, -2}, {-1, -1}, {-2, 0}, {-1, 1}, {0, 2}, {1, 1}, {2, 0}, {1, -1}};
    FOR(i, n) {
        FOR(j, m) {
            if (dp[i][j] == -1) continue;
            FORR2(dx, dy, jumpDirs) {
                int nx = i + dx, ny = j + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (dp[nx][ny] == -1) continue;
                if (dp[nx][ny] - dp[i][j] - 2 >= 100) {
                    ans1++;
                }
            }
        }
    }

    FOR(i, n) {
        FOR(j, m) {
            if (dp[i][j] == -1) continue;
            REP(x, -20, 20) {
                REP(y, -20, 20) {
                    if (abs(x) + abs(y) > 20) continue;
                    if (i + x < 0 || i + x >= n || j + y < 0 || j + y >= m) continue;
                    if (dp[i + x][j + y] == -1) continue;
                    if (dp[i + x][j + y] - dp[i][j] - abs(x) - abs(y) >= 100) {
                        ans2++;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto start = std::chrono::high_resolution_clock::now();

#if SINGLE_TEST
    solve();
#else
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
#endif

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << "Time: " << duration.count() / 1e6 << " ms" << std::endl;

    debug(ans1);
    debug(ans2);

    return 0;
}
