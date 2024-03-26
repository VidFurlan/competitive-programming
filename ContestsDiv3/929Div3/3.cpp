#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, a, b, ans = 0;
        cin >> a >> b >> l;

        int ca = log(l) / log(a), cb = log(l) / log(b);

        if (a == b) {
            int m = 0;
            while (l / (float) a == floor(l / (float) a)) {
                m++;
                l /= a;
            }
            cout << m + 1 << endl;
            continue;
        }

        unordered_set<int> set;

        for (int i = 0; i < ca + 2; i++)
            for (int j = 0; j < cb + 2; j++)
                if (l >= pow(a, i) * pow(b, j) && l % (int)(pow(a, i) * pow(b, j)) == 0)
                    set.insert(l / pow(a, i) * pow(b, j));

        cout << set.size() << endl;
    }
}
