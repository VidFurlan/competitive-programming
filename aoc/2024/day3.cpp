#include <bits/stdc++.h>
#include <cctype>
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

const string fileName = "day3.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> lines = elf.readStrings();
    string line;
    FORR(l, lines) line += l;
    getline(file, line);
    int n = SZ(line);
    bool f = 1;
    FOR(i, n) {
        if (i+4 >= n) break;
        if (i+7 < n) {
            string s = line.substr(i, 7);
            if (s == "don't()") {
                f = 0;
                cout << "don't()" << endl;
            }
            s = line.substr(i, 4);
            if (s == "do()") {
                f = 1;
                cout << "do()" << endl;
            }
        }
        string s = line.substr(i, 4);
        cout << s << endl;
        if (s == "mul(") {
            i += 4;
            int num1 = 0;
            int num2 = 0;
            while (i < n && isdigit(line[i])) {
                num1 = num1 * 10 + (line[i] - '0');
                i++;
            }
            if (line[i] == ',') {
                i++;
                while (i < n && isdigit(line[i])) {
                    num2 = num2 * 10 + (line[i] - '0');
                    i++;
                }
            }
            if (line[i] == ')') {
                ans1 += num1 * num2;
                ans2 += num1 * num2 * f;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#if SINGLE_TEST
    solve();
#else
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
#endif
    debug(ans1);
    debug(ans2);

    return 0;
}