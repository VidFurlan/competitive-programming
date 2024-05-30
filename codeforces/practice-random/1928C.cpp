#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n, x; cin >> n >> x;
    set<int> st;
    x--;
    for (int num : {n - x - 1, n + x - 1}) {
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                for (int div : {i, num / i}) {
                    int k = div + 2;
                    if (k % 2)
                        continue;
                    k /= 2;
                    if (k > x)
                        st.insert(k);
                }
            }
        } 
    }
    cout << st.size() << endl;
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
