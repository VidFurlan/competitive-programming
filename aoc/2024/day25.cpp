#include <array>
#include <bitset>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <chrono>
#include <algorithm>
#include <map>
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

const string fileName = "day25.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readStrings();
    vector<array<int, 5>> keys;
    vector<array<int, 5>> locks;
    array<int, 5> cur;
    FOR(i, SZ(in)) {
        cur.fill(-1);
        FOR(j, 7) {
            string row = in[i + j];
            FOR(k, 5) {
                cur[k] += row[k] == '#';
            }
        }
        if (in[i][0] == '#') {
            keys.push_back(cur);
        } 
        else {
            locks.push_back(cur);
        }
        i += 6;
    }
    int n = SZ(keys);
    int m = SZ(locks);
    // FORR(k, keys) { FORR(i, k) cout << i << " "; cout << endl; } cout << endl;
    // FORR(k, locks) { FORR(i, k) cout << i << " "; cout << endl; } cout << endl;
    FORR(k, keys) {
        FORR(l, locks) {
            array<int, 5> space;
            FOR(i, 5) space[i] = 5 - l[i] - k[i];
            bool ok = 1;
            FORR(i, space) if (i < 0) ok = 0;
            ans1 += ok;
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

