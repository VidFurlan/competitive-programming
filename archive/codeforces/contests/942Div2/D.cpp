#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve(int i, ostream& out) {
    out << 1000000000000 - 500000 + i << " ";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ofstream output("output.txt");

    int t = 500000;

    while (t--) {
        solve(t, output);
    }

    output.close();
    return 0;
}
