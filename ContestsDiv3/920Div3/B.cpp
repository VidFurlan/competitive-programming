#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;

    while (t--) {
        int n, _1 = 0, _0 = 0;
        string s, t;
        cin >> n >> s >> t;

        while (n--) {
            if (s[n] == t[n])
                continue;

            if (t[n] == '1')
                _1++;
            else 
                _0++;
        }
                
        cout << max(_0, _1) << '\n';
    }
}
