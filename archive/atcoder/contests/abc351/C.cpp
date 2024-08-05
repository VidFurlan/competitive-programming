#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<int> stk;
    for (int i = 0; i < n; i++) {
        stk.push_back(a[i]);
        while (stk.size() > 1 && stk[stk.size() - 1] == stk[stk.size() - 2]) {
            stk.pop_back();
            stk.back() = stk.back() + 1;
        }
        /*cout << i << " -> ";
        for (int b : stk)
            cout << b << " ";
        cout << endl;*/
    }

    cout << stk.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
