#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

// Solution
// If all elements of a % 2 == 0 or 1 then the answer cant be 2
// Then we can try 4 since the % will be eqaul eather to 3, or 0
// We notice that if the the previous % are all the same, then the
// next % of prev * 2 will eather be 0 or prev * 2 - 1

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    FORR(i, a) cin >> i;
    ll i = 2;

    for(; i < LL_INF; i *= 2) {
        set<ll> st;
        FORR(j, a) {
            st.insert(j % i);
            if (st.size() > 2)
                break;
        }

        if (st.size() == 2) {
            // FORR(j, a) 
            //     cout << (j % i) << " ";
            // cout << endl;
            cout << i << endl;
            return;
        }
    }

    // Shouldnt ever be reached
    cout << 2 << endl;
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
