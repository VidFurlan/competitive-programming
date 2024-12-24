#include <bitset>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <chrono>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
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

const string fileName = "day24.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readLines();
    map<string, int> status;
    map<string, tuple<string, string, string>> adj;
    bitset<64> numX, numY;
    FORR(s, in) {
        if (s.empty()) continue;
        if (s[3] == ':') {
            status[s.substr(0, 3)] = s[5] - '0';
            if (s[0] == 'x') numX[stoi(s.substr(1, 2))] = s[5] - '0';
            if (s[0] == 'y') numY[stoi(s.substr(1, 2))] = s[5] - '0';
        }
        else {
            string u = s.substr(0, 3);
            if (s[4] != 'O') {
                string v = s.substr(8, 3);
                string op = s.substr(4, 3);
                string p = s.substr(15, 3);
                adj[p] = {u, v, op};
            }
            else {
                string v = s.substr(7, 3);
                string op = s.substr(4, 2);
                string p = s.substr(14, 3);
                adj[p] = {u, v, op};
            }
        }
    }
    bitset<64> bs;

    auto dfs = [&](string p, auto dfs) -> int {
        if (status.count(p)) return status[p];
        auto [u, v, op] = adj[p];
        int a = dfs(u, dfs);
        int b = dfs(v, dfs);
        if (op == "AND") return a & b;
        if (op == "OR") return a | b;
        if (op == "XOR") return a ^ b;
        return 0;
    };

    FOR(i, 64) {
        string p = "z";
        if (i < 10) p += '0';
        p += to_string(i);
        if (adj.count(p) == 0) continue;
        bs[i] = dfs(p, dfs);
    }
    ans1 = bs.to_ullong();
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
