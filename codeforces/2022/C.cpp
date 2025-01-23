#include <bits/stdc++.h>
using namespace std;
#define SINGLE_TEST 0

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
    int n; cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    vvi dp(3, vi(n/3+1));
    // 0 =
    // 1 L
    // 2 J
    FOR(i, n/3) {
        //debug(i);

        int sumStraight[2] = {0, 0};
        FOR(j, 3) {
            sumStraight[0] += s[0][i*3+j] == 'A';
            sumStraight[1] += s[1][i*3+j] == 'A';
        }
        dp[0][i+1] = dp[0][i] + (sumStraight[0] >= 2) + (sumStraight[1] >= 2);

        int sumL = 0;
        sumL += s[0][i*3+0] == 'A';
        sumL += s[1][i*3+0] == 'A';
        sumL += s[1][i*3+1] == 'A';
        dp[1][i+1] = dp[0][i] + (sumL >= 2);

        //debug(sumL);

        int sumJ = 0;
        sumJ += s[0][i*3+0] == 'A';
        sumJ += s[0][i*3+1] == 'A';
        sumJ += s[1][i*3+0] == 'A';
        dp[2][i+1] = dp[0][i] + (sumJ >= 2);

        //debug(sumJ);
        
        if (i > 0) {
            int sumL[2] = {0, 0};
            FOR(j, 3) {
                sumL[0] += s[0][(i-1)*3+j+1] == 'A';
                sumL[1] += s[1][(i-1)*3+j+2] == 'A';
                //cout << "\t" << s[0][(i-1)*3+j+1] << " " << s[1][(i-1)*3+j+2] << endl; 
            }
            dp[1][i+1] = max(dp[1][i+1], dp[1][i] + (sumL[0] >= 2) + (sumL[1] >= 2));
            //cout << "sumSegL: " << sumL[0] << " " << sumL[1] << endl;

            int sumJ[2] = {0, 0};
            FOR(j, 3) {
                sumJ[0] += s[0][(i-1)*3+j+2] == 'A';
                sumJ[1] += s[1][(i-1)*3+j+1] == 'A';
                //cout << "\t" << s[0][(i-1)*3+j+2] << " " << s[1][(i-1)*3+j+1] << endl;
            }
            dp[2][i+1] = max(dp[2][i+1], dp[2][i] + (sumJ[0] >= 2) + (sumJ[1] >= 2));
            //cout << "sumSegJ: " << sumJ[0] << " " << sumJ[1] << endl;
        }

        int sumEndL = 0;
        sumEndL += s[0][i*3+1] == 'A';
        sumEndL += s[0][i*3+2] == 'A';
        sumEndL += s[1][i*3+2] == 'A';
        dp[0][i+1] = max(dp[0][i+1], dp[1][i+1] + (sumEndL >= 2));

        //debug(sumEndL);

        int sumEndJ = 0;
        sumEndJ += s[0][i*3+2] == 'A';
        sumEndJ += s[1][i*3+1] == 'A';
        sumEndJ += s[1][i*3+2] == 'A';
        dp[0][i+1] = max(dp[0][i+1], dp[2][i+1] + (sumEndJ >= 2));

        //debug(sumEndJ);

        //cout << dp[0][i+1] << " " << dp[1][i+1] << " " << dp[2][i+1] << endl << endl;
    }
    //cout << "ans: ";
    cout << dp[0][n/3] << endl;
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
