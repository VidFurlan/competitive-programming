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

const string fileName = "day8.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readStrings();
    map<char, vector<pii>> mp;
    FOR(i, SZ(in)) {
        FOR(j, SZ(in[i])) {
            if (in[i][j] != '.') {
                mp[in[i][j]].push_back({i, j});
            }
        }
    }
    vvi seen1(SZ(in), vi(SZ(in[0])));
    vvi seen2(SZ(in), vi(SZ(in[0])));
    FORR2(k, v, mp) {
        FOR(i, SZ(v)) {
            REP(j, i + 1, SZ(v) - 1) {
                int xDiff = v[j].fi - v[i].fi;
                int yDiff = v[j].se - v[i].se;
                pii p1 = {v[i].fi - xDiff, v[i].se - yDiff};
                pii p2 = {v[j].fi + xDiff, v[j].se + yDiff};
                seen2[v[i].fi][v[i].se] = 1;
                seen2[v[j].fi][v[j].se] = 1;
                bool f = 0;
                while (p1.fi >= 0 && p1.fi < SZ(in) && p1.se >= 0 && p1.se < SZ(in[0])) {
                    if (!f) {
                        seen1[p1.fi][p1.se] = 1;
                        f = 1;
                    }
                    seen2[p1.fi][p1.se] = 1;
                    p1.fi -= xDiff;
                    p1.se -= yDiff;
                }
                f = 0;
                while (p2.fi >= 0 && p2.fi < SZ(in) && p2.se >= 0 && p2.se < SZ(in[0])) {
                    if (!f) {
                        seen1[p2.fi][p2.se] = 1;
                        f = 1;
                    }
                    seen2[p2.fi][p2.se] = 1;
                    p2.fi += xDiff;
                    p2.se += yDiff;
                }
            }
        }
    }

    FOR(i, SZ(in)) {
        FOR(j, SZ(in[i])) {
            ans1 += seen1[i][j];
            ans2 += seen2[i][j];
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
