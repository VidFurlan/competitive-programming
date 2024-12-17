#include <bits/stdc++.h>
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

const string fileName = "day17.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

ll combo(ll operand, ll a, ll b, ll c) {
    if (operand == 4) return a;
    if (operand == 5) return b;
    if (operand == 6) return c;
    if (operand == 7) throw runtime_error("Reserved operand");
    return operand;
}

void solve() {
    vector<string> in = elf.readStrings();
    ll a = stoll(in[2]);
    ll b = stoll(in[5]);
    ll c = stoll(in[8]);

    vl v;
    string s = in[10];
    ll cur = 0;
    FOR(i, SZ(s)) {
        if (s[i] == ',') {
            v.push_back(cur);
            cur = 0;
        }
        else {
            cur = cur * 10 + (s[i] - '0');
        }
    }
    v.push_back(cur);

    int n = SZ(v);
    string ans;
    for (int i = 0; i < n;) {
        ll op = v[i], num = v[i + 1];
        i += 2;

        if (op == 0) {
            a /= 1ll << combo(num, a, b, c);
        }
        else if (op == 1) {
            b ^= num;
        }
        else if (op == 2) {
            b = combo(num, a, b, c) % 8;
        }
        else if (op == 3) {
            if (a != 0) {
                i = num;
            }
        }
        else if (op == 4) {
            b ^= c;
        }
        else if (op == 5) {
            ans += to_string(combo(num, a, b, c) % 8) + ",";
        }
        else if (op == 6) {
            b = a / (1ll << combo(num, a, b, c));
        }
        else if (op == 7) {
            c = a / (1ll << combo(num, a, b, c));
        }
    }
    ans.pop_back();
    cout << ans << endl;
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
