#include <bits/stdc++.h>
#include <cctype>
#include <string>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    string s, t; cin >> s >> t;

    int i = 0, j = 0;
    for (; j < ((s[2] == 'X') ? 2 : 3) && i < s.size(); i++) {
        if (s[i] == tolower(t[j]))
            j++;
    }

    if (j == ((t[2] == 'X') ? 2 : 3))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
