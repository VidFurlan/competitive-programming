#include <bits/stdc++.h>
#include <chrono>
#include <string>
#include <unordered_map>
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

const string fileName = "day11.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ull ans2 = 0;

int mxD = 25;
map<pair<string, int>, ull> dp;
ull dfs(string num, int d) {
    if (d == mxD) {
        return 1;
    }
    if (dp[{num, d}]) {
        return dp[{num, d}];
    }
    ull res = 0;
    if (num.size() % 2 == 0) {
        res += dfs(to_string(stoll(num.substr(0, num.size() / 2))), d+1);
        res += dfs(to_string(stoll(num.substr(num.size() / 2, num.size() / 2))), d+1);
    }
    else if (num == "0") {
        res += dfs("1", d+1);
    }
    else {
        res += dfs(to_string(stoll(num) * 2024), d+1);
    }
    return dp[{num, d}] = res;
}

void solve() {
    vi in = elf.readInts();
    FORR(x, in) {
        ans1 += dfs(to_string(x), 0);
    }
    dp.clear();
    mxD = 75;
    FORR(x, in) {
        ans2 += dfs(to_string(x), 0);
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
