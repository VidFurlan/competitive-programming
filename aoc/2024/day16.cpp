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

const string fileName = "day16.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readStrings();
    int n = SZ(in), m = SZ(in[0]);
    vector<vvl> dp(n, vvl(m, vl(4, LLINF)));
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
    dp[sx][sy][0] = 0;
    queue<tuple<int, int, int, int>> q;
    q.push({sx, sy, 0, 0});
    while (SZ(q)) {
        auto [x, y, d, c] = q.front();
        q.pop();
        FOR(i, 4) {
            int nx = x + dirs[i].fi, ny = y + dirs[i].se;
            if (in[nx][ny] == '#') continue;
            int nc = c + 1 + (d != i) * 1000;
            if (nc < dp[nx][ny][i]) {
                dp[nx][ny][i] = nc;
                q.push({nx, ny, i, nc});
            }
        }
    }
    ans1 = LLINF;
    FOR(i, 4) ans1 = min(ans1, dp[ex][ey][i]);

    set<pii> s;
    auto dfs = [&](int x, int y, int d, int c, auto dfs) -> int {
        if (in[x][y] == '#') return 0;
        if (x == ex && y == ey && c == ans1) {
            s.insert({x, y});
            return 1;
        }
        bool f = 0;
        FOR(i, 4) {
            int nx = x + dirs[i].fi, ny = y + dirs[i].se;
            int nc = c + 1 + (d != i) * 1000;
            if (nc == dp[nx][ny][i]) {
                f |= dfs(nx, ny, i, nc, dfs);
            }
        }
        if (f) s.insert({x, y});
        return f;
    };
    dfs(sx, sy, 0, 0, dfs);
    ans2 = SZ(s);
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
