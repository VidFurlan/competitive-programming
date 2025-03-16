#include <bits/stdc++.h>
#include <string>
#include <vector>
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

void solve() {
    string in; getline(cin, in);
    // split in into words
    vector<string> a = {"0"};
    string s;
    FORR(c, in) {
        if (c != ' ') {
            s.push_back(c);
        }
        else if (SZ(s) > 0) {
            a.push_back(s);
            s.clear();
        }
    }
    a.push_back(s);

    int n = SZ(a);
    FOR(i, n - 1) {
        FORR(ss, a) cout << ss << " "; cout << endl;

        if (SZ(a[i + 1]) < SZ(a[i])) {
            cout << "-1" << endl;
            return;
        }

        if (SZ(a[i + 1]) > SZ(a[i])) {
            FOR(j, SZ(a[i + 1])) {
                if (a[i + 1][j] == '*') {
                    a[i + 1][j] = '6';
                }
            }
            continue;
        }

        vi pos;
        FOR(j, SZ(a[i])) {
            if (a[i + 1][j] == '*') {
                pos.push_back(j);
            }
        }

        if (SZ(pos) != 0) {
            string mn;
            FOR(j, SZ(a[i])) {
                mn += '9';
            }
            vector<bool> bin(SZ(pos), false);

            // Try all possible values for the positions (6 or 9)
            FOR(j, 1 << SZ(pos)) {
                FOR(k, SZ(pos)) {
                    if (j & (1 << k)) {
                        bin[k] = true;
                    }
                    else {
                        bin[k] = false;
                    }
                }
                FOR(k, SZ(pos)) {
                    if (bin[k]) {
                        a[i + 1][pos[k]] = '6';
                    }
                    else {
                        a[i + 1][pos[k]] = '9';
                    }
                    if (a[i + 1] < mn && a[i] <= a[i + 1]) {
                        mn = a[i + 1];
                    }
                }
            }
            a[i + 1] = mn;
        }

        if (a[i] > a[i + 1]) {
            cout << "-4" << endl;
            return;
        }
    }

    REP(i, 1, n - 1) 
        cout << a[i] << " ";
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
