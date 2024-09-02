#include <bits/stdc++.h>
#include <string>
using namespace std;
#define SINGLE_TEST 1

typedef long long ll;
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
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

// Shift, by
char shiftBack(char a, char b) {
    b -= 'a' - 1;
    if (a - b < 'a')
        return a - b + 26;
    return a - b;
}

void solve() {
    string s, tt;
    getline(cin, s);
    getline(cin, tt);
    
    string t;
    FORR(c, tt)
        if (c != ' ')
            t.push_back(c);

    int n = s.size(), m = t.size();
    int j = 0;
    string key;
    for(int i = 0; i < s.size() && j < t.size(); i++) {
        if (s[i] == ' ') continue;

        key.push_back(shiftBack(s[i], t[j]));
        j++;
    }
    // cout << key << endl;

    j = 0;
    FOR(i, n) {
        if (s[i] == ' ') {
            cout << ' ';
            continue;
        }
        
        // cout << s[i] << " -> " << key[j % key.size()] << " -> ";
        cout << shiftBack(s[i], key[j % key.size()]);
        j++;
    }
    cout << endl;
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

    return 0;
}
