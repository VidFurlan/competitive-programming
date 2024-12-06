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

const string fileName = "day6.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> g = elf.readStrings();
    int n = SZ(g), m = SZ(g[0]);
    vector<pii> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
    int x, y;
    FOR(i, n) FOR(j, m) if (g[i][j] == '^') {
        y = i, x = j;
        break;
    }
    int sy = y, sx = x;
    int dir = 0;
    vector<vvi> seenDir(n, vvi(m, vi(4)));
    vvi seen(n, vi(m));
    vvi seenAll(n, vi(m));
            
    while (seenDir[y][x][dir] == 0) {
        seenDir[y][x][dir] = 1;
        ans1 += seenAll[y][x] == 0;
        seenAll[y][x] = 1;
        auto [i, j] = dirs[dir];
        if (i + y < 0 || i + y >= n || j + x < 0 || j + x >= m) {
            break;
        }
        if (g[y+i][x+j] == '#') {
            dir++;
            dir %= 4;
            continue;
        }
        y += i;
        x += j;
        //debug(dir);
        //debug(x); debug(y); cout << endl;
    }

    FOR(yy, n) FOR(xx, m) {
        if (g[yy][xx] == '.' && seenAll[yy][xx] == 1) {
            x = sx, y = sy;
            dir = 0;
            vector<vvi> seenDir(n, vvi(m, vi(4)));
            vvi seen(n, vi(m));

            bool f = 1;
            g[yy][xx] = '#';
            while (seenDir[y][x][dir] == 0) {
                seenDir[y][x][dir] = 1;
                seen[y][x] = 1;
                auto [i, j] = dirs[dir];
                if (i + y < 0 || i + y >= n || j + x < 0 || j + x >= m) {
                    f = 0;
                    break;
                }
                if (g[y+i][x+j] == '#') {
                    dir++;
                    dir %= 4;
                    continue;
                }
                y += i;
                x += j;
                //debug(dir);
                //debug(x); debug(y); cout << endl;
            }
            ans2 += f;
            g[yy][xx] = '.';
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
