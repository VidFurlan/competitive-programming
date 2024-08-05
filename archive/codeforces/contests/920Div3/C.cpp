#include <bits/stdc++.h>
using namespace std;

int main () {
    long long t;
    cin >> t;
    while (t--) {
        long long n, m, f, a, b;
        cin >> n >> f >> a >> b;
        vector<long long> msg (n);
        m = n;

        while (m--) 
            cin >> msg[m];
        msg.push_back(0);
        sort(msg.begin(), msg.end());

        bool valid = true;
        for (m = 0; m < n; m++) {
            long long dif = msg[m + 1] - msg[m];
            f -= min(dif * a, b);
            if (f <= 0) {
                valid = false;
                break;
            }
        }

        cout << ((valid)?"YES\n":"NO\n");
    }
}
