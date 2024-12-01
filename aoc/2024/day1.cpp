#include <bits/stdc++.h>
using namespace std;
#define SINGLE_TEST 1

const string fileName = "day1.in";

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

ifstream file(fileName);
ll ans1 = 0;
ll ans2 = 0;

void solve() {
    string line;
    vl a, b;
    bool f = 0;
    while (file >> line) {
        if (f) a.push_back(stoi(line));
        else b.push_back(stoi(line));
        f = !f;
    }

    sort(ALL(a));
    sort(ALL(b));
    FOR(i, SZ(a)) {
        ans1 += abs(a[i] - b[i]);
    }

    map<ll, ll> mp;
    FORR(x, b) mp[x]++;
    FORR(x, a) ans2 += mp[x] * x;
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
