#include <bits/stdc++.h>
#include <chrono>
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

const string fileName = "day10.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

vector<string> in = elf.readStrings();
int n = SZ(in), m = SZ(in[0]);
set<pii> s;
int tot = 0;

vector<pii> dirs = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

void dfs(int i, int j) {
    if (in[i][j] == '9') {
        s.insert({i, j});
        tot++;
    }
    FORR2(di, dj, dirs) {
        int ni = i + di, nj = j + dj;
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if (in[ni][nj] != '.' && in[ni][nj] - 1 == in[i][j]) {
            dfs(ni, nj);
        }
    }
}

void solve() {
    FOR(i, n) {
        FOR(j, m) {
            if (in[i][j] == '0') {
                s.clear();
                tot = 0;
                dfs(i, j);
                ans1 += SZ(s);
                ans2 += tot;
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
