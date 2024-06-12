#include <bits/stdc++.h>
#include <iomanip>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

int n, m; 
map<int, int> cnt;

void dfs(vector<vector<int>> &mp, vector<string> &a, int i, int j, int num) {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (a[i][j] == '.') return;
    if (mp[i][j] != 0) return;

    mp[i][j] = num;
    cnt[num]++;
    dfs(mp, a, i + 1, j, num);
    dfs(mp, a, i - 1, j, num);
    dfs(mp, a, i, j + 1, num);
    dfs(mp, a, i, j - 1, num);
}

void solve() {
    cin >> n >> m;
    cnt.clear();
    vector<string> a(n);
    vector<vector<int>> mp(n, vector<int>(m, 0));
    FORR(i, a) cin >> i;
    FOR(i, n)
        FOR(j, m)
            dfs(mp, a, i, j, i * m + j + 1);
    

    int ans = 0;
    FOR(i, n) {
        set<int> st;
        int sum = 0;
        FOR(j, m) {
            st.insert(mp[i][j]);
            if (i > 0)
                st.insert(mp[i - 1][j]);
            if (i < n - 1)
                st.insert(mp[i + 1][j]);
            if (mp[i][j] == 0)
                sum++;
        }
        //cout << "zero: " << sum << " ";
        FORR(j, st)
            sum += cnt[j];
        ans = max(ans, sum);
        //cout << "row: " << i << " " << sum << endl;
    }

    FOR(j, m) {
        set<int> st;
        int sum = 0;
        FOR(i, n) {
            st.insert(mp[i][j]);
            if (j > 0)
                st.insert(mp[i][j - 1]);
            if (j < m - 1)
                st.insert(mp[i][j + 1]);
            if (mp[i][j] == 0)
                sum++;
        }
        //cout << "zero: " << sum << " ";
        FORR(j, st)
            sum += cnt[j];
        ans = max(ans, sum);
        //cout << "col: " << j << " " << sum << endl;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
