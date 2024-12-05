#include <bits/stdc++.h>
#include <chrono>
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

const string fileName = "day5.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readStrings();
    vvi a;
    vector<pii> rule;
    FORR(s, in) {
        if (s.empty()) continue;
        if (s[2] == '|') {
            rule.push_back({stoi(s.substr(0, 2)), stoi(s.substr(3, 2))});
        }
        else {
            vi v;
            FOR(i, SZ(s)) {
                if (s[i] == ',') {
                    v.push_back(stoi(s.substr(i - 2, 2)));
                }
            }
            v.push_back(stoi(s.substr(SZ(s) - 2, 2)));
            a.push_back(v);
        }
    }
    
    map<int, set<int>> before;
    FORR2(x, y, rule) {
        before[y].insert(x);
    }

    FORR(v, a) {
        bool ok = 1;
        map<int, int> mp;
        FOR(i, SZ(v)) mp[v[i]] = i;
        FORR2(x, y, rule) {
            if (mp.find(x) == mp.end() || mp.find(y) == mp.end()) continue;
            if (mp[x] > mp[y]) {
                ok = 0;
                break;
            }
        }

        ans1 += v[SZ(v) / 2] * ok;

        if (!ok) {
            vi ans;
            ans.push_back(v[0]);
            REP(i, 1, SZ(v) - 1) {
                int l = 0;
                FOR(j, SZ(ans)) {
                    if (before[v[i]].find(ans[j]) != before[v[i]].end()) {
                        l = j + 1;
                    }
                }
                ans.insert(ans.begin() + l, v[i]);
            }
            ans2 += ans[SZ(ans) / 2];
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
