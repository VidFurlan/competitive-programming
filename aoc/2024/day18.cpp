#include <bits/stdc++.h>
#include <string>
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

const string fileName = "day18.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = LLINF;
ll ans2 = LLINF;

void solve() {
    vector<string> in = elf.readStrings();
    int n = 71, m = 71;
    vector<string> g(n, string(m, '.'));
    vector<pii> c;
    FORR(s, in) {
        int y = stoi(s.substr(0, s.find(',')));
        int x = stoi(s.substr(s.find(',') + 1));
        c.push_back({x, y});
    }
    FOR(i, 1024) g[c[i].fi][c[i].se] = '#';
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    vvi dp(n, vi(m, INF));
    vector<pii> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (SZ(q)) {
        auto [x, y, d] = q.front();
        q.pop();
        if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#') continue;
        if (dp[x][y] <= d) continue;
        dp[x][y] = d;
        if (x == n - 1 && y == m - 1) {
            ans1 = min(ans1, (ll)d);
        }
        FORR2(dx, dy, dirs) {
            q.push({x + dx, y + dy, d + 1});
        }
    }
    int ans = INF;
    int depth = 1024;
    do {
        ans2 = ans;
        ans = INF;
        g[c[depth].fi][c[depth].se] = '#';
        q.push({0, 0, 0});
        vvi dp(n, vi(m, INF));
        while (SZ(q)) {
            auto [x, y, d] = q.front();
            q.pop();
            if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#') continue;
            if (dp[x][y] <= d) continue;
            dp[x][y] = d;
            if (x == n - 1 && y == m - 1) {
                ans = min(ans, d);
            }
            FORR2(dx, dy, dirs) {
                q.push({x + dx, y + dy, d + 1});
            }
        }
        depth++;
        //cout << depth << " " << ans << endl;
    } while (ans != INF);
    cout << c[depth-1].se << "," << c[depth-1].fi << endl;
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
