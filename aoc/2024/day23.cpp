#include <bits/stdc++.h>
#include <numeric>
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

const int MOD = 16777216;
const int INF = 1e9;
const ll LLINF = 1e18;

const string fileName = "day23.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
string ans2;

void solve() {
    vector<string> in = elf.readStrings();
    unordered_map<string, set<string>> adj;
    FORR(s, in) {
        adj[s.substr(0, 2)].insert(s.substr(3, 2));
        adj[s.substr(3, 2)].insert(s.substr(0, 2));
    }
    set<set<string>> tComp;
    FORR2(a, dummy, adj) {
        FORR(b, adj[a]) {
            FORR(c, adj[b]) {
                if (c != a && adj[a].find(c) != adj[a].end() && (a[0] == 't' || b[0] == 't' || c[0] == 't')) {
                    tComp.insert({a, b, c});
                }
            }
        }
    }
    ans1 = SZ(tComp);

    set<set<string>> tComp2;
    set<string> seenAll;
    FORR2(a, dummy, adj) {
        if (seenAll.find(a) != seenAll.end()) continue;
        set<string> con, seen;
        queue<string> q;
        q.push(a);
        while (SZ(q)) {
            string b = q.front();
            q.pop();
            if (seen.find(b) != seen.end()) continue;
            seen.insert(b);
            bool f = 1;
            FORR(c, con) {
                if (b != c && adj[b].find(c) == adj[b].end()) {
                    f = 0;
                    break;
                }
            }
            if (f) {
                con.insert(b);
                FORR(c, adj[b]) {
                    q.push(c);
                }
            }
        }
        FORR(c, con) {
            seenAll.insert(c);
        }
        tComp2.insert(con);
    }
    set<string> mx;
    FORR(c, tComp2) {
        if (SZ(c) > SZ(mx)) {
            mx = c;
        }
    }
    FORR(x, mx) {
        ans2 += x + ',';
    }
    ans2.pop_back();
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
