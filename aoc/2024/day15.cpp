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

const string fileName = "day15.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readStrings();
    vector<string> g, g2;
    string moves;
    FORR(s, in) {
        if (s[0] == '#') {
            g.push_back(s);
            g2.push_back("");
            FORR(c, s) {
                if (c == '#') {
                    g2.back() += ("##");
                }
                else if (c == '.') {
                    g2.back() += "..";
                }
                else if (c == 'O') {
                    g2.back() += "[]";
                }
                else if (c == '@') {
                    g2.back() += "@.";
                }
            }
        }
        else {
            moves += s;
        }
    }

    int x = 0, y = 0;
    FOR(i, SZ(g)) {
        FOR(j, SZ(g[i])) {
            if (g[i][j] == '@') {
                x = i;
                y = j;
                g[i][j] = '.';
            }
        }
    }

    map<char, pii> dir = {
        {'^', {-1, 0}},
        {'v', {1, 0}},
        {'<', {0, -1}},
        {'>', {0, 1}}
    };
    FORR(move, moves) {
        int dx = dir[move].fi + x;
        int dy = dir[move].se + y;
        if (g[dx][dy] == '#') continue;
        if (g[dx][dy] == '.') {
            x = dx;
            y = dy;
        }
        else {
            int ddx = dx;
            int ddy = dy;
            while (g[ddx][ddy] == 'O') {
                ddx += dir[move].fi;
                ddy += dir[move].se;
            }
            if (g[ddx][ddy] == '.') {
                x = dx;
                y = dy;
                g[dx][dy] = '.';
                g[ddx][ddy] = 'O';
            }
        }
        // FORR(row, g) cout << row << endl; cout << endl;
    }

    FOR(i, SZ(g)) {
        FOR(j, SZ(g[i])) {
            if (g[i][j] == 'O') {
                ans1 += i * 100ll + j;
            }
        }
    }
    
    x = 0, y = 0;
    FOR(i, SZ(g2)) {
        FOR(j, SZ(g2[i])) {
            if (g2[i][j] == '@') {
                x = i;
                y = j;
                g2[i][j] = '.';
            }
        }
    }

    auto dfs = [&](int x, int y, const pii &dir, auto dfs) -> bool {
        if (g2[x][y] == '#') return false;
        if (g2[x][y] == '[') {
            if (dfs(x + dir.fi, y + dir.se, dir, dfs) &&
                    dfs(x + dir.fi, y + dir.se + 1, dir, dfs))
                return true;
            else return false;
        }
        else if (g2[x][y] == ']') {
            if (dfs(x + dir.fi, y + dir.se - 1, dir, dfs) &&
                    dfs(x + dir.fi, y + dir.se, dir, dfs))
                return true;
            else return false;
        }
        return true;
    };

    auto moveDfs = [&](int x, int y, const pii &dir, auto moveDfs) -> void {
        if (g2[x][y] == '#') return;
        if (g2[x][y] == '[') {
            moveDfs(x + dir.fi, y + dir.se, dir, moveDfs);
            moveDfs(x + dir.fi, y + dir.se + 1, dir, moveDfs);
            g2[x][y] = '.';
            g2[x][y + 1] = '.';
            g2[x + dir.fi][y + 1] = ']';
            g2[x + dir.fi][y] = '[';
        }
        if (g2[x][y] == ']') {
            moveDfs(x + dir.fi, y + dir.se - 1, dir, moveDfs);
            moveDfs(x + dir.fi, y + dir.se, dir, moveDfs);
            g2[x][y] = '.';
            g2[x][y - 1] = '.';
            g2[x + dir.fi][y - 1] = '[';
            g2[x + dir.fi][y] = ']';
        }
    };

    FORR(move, moves) {
        //cout << "Move: " << move << endl;
        int dx = dir[move].fi + x;
        int dy = dir[move].se + y;
        if (g2[dx][dy] == '#') continue;
        if (g2[dx][dy] == '.') {
            x = dx;
            y = dy;
        }
        else {
            if (move == '<' || move == '>') {
                int ddx = dx;
                int ddy = dy;
                while (g2[ddx][ddy] == '[' || g2[ddx][ddy] == ']') {
                    ddx += dir[move].fi;
                    ddy += dir[move].se;
                }
                if (g2[ddx][ddy] == '.') {
                    g2[ddx][ddy] = (move == '<' ? '[' : ']');
                    while (ddx != dx || ddy != dy) {
                        ddx -= dir[move].fi;
                        ddy -= dir[move].se;
                        g2[ddx][ddy] = (g2[ddx][ddy] == '[' ? ']' : '[');
                    }
                    g2[dx][dy] = '.';
                    x = dx;
                    y = dy;
                }
            }
            else {
                if (dfs(dx, dy, dir[move], dfs)) {
                    x = dx;
                    y = dy;
                    moveDfs(x, y, dir[move], moveDfs);
                }
            }
        }
        //g2[x][y] = '@';
        //FORR(row, g2) cout << row << endl; cout << endl;
        //g2[x][y] = '.';
    }

    FOR(i, SZ(g2)) {
        FOR(j, SZ(g2[i])) {
            if (g2[i][j] == '[') {
                ans2 += i * 100ll + j;
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
