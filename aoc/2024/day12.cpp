#include <chrono>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
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

const string fileName = "day12.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> g = elf.readStrings();
    int n = SZ(g), m = SZ(g[0]);
    int n2 = 2*n, m2 = 2*m;
    vector<pii> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
    vector<pii> dirs2 = {
        {-1, 1},
        {1, 1},
        {1, -1},
        {-1, -1}
    };

    vector<string> gg;
    FORR(r, g) {
        gg.push_back("");
        FORR(c, r) {
            gg.back() += c;
            gg.back() += c;
        }
        gg.push_back(gg.back());
    }
 
    int area, par, edge;
    char c;
    vvi seen(n, vi(m));
    vvi seen2(n2, vi(m2, -1));
    
    auto dfs = [&](int i, int j, auto&& dfs) -> void {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            par++;
            return;
        }
        if (g[i][j] != c) {
            par++;
            return;
        }
        if (seen[i][j]) return;
        seen[i][j] = 1;
        area++;
        FORR2(di, dj, dirs) dfs(i + di, j + dj, dfs);
    };

    auto dfs2 = [&](int i, int j, auto&& dfs2) -> int {
        if (i < 0 || i >= n2 || j < 0 || j >= m2) {
            return 1;
        }
        if (gg[i][j] != c) {
            return 1;
        }

        if (seen2[i][j] != -1) return 0;
        seen2[i][j] = 0;
        int t = 0;
        FORR2(di, dj, dirs) {
            if (dfs2(i + di, j + dj, dfs2))
                t++;
        }

        seen2[i][j] = t;
        if (t == 2) {
            edge++;
            return 0;
        }

        if (t != 0) return 0;

        t = 0;
        FORR2(di, dj, dirs2) {
            if (di + i >= n2 || di + i < 0 || dj + j >= m2 || dj + j < 0 || gg[di + i][dj + j] != c)
                t++;
        }
        if (t == 1) {
            edge++;
        }
        return 0;
    };

    FOR(i, n) FOR(j, m) {
        if (!seen[i][j]) {
            c = g[i][j];
            par = 0, area = 0, edge = 0;
            dfs(i, j, dfs);
            dfs2(i*2, j*2, dfs2);
            ans1 += par * area;
            ans2 += edge * area;
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
