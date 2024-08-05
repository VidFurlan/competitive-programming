#include <bits/stdc++.h>
using namespace std;

#define A(a) (a).begin(), (a).end()
#define K first 
#define V second 
#define M 1000000007
#define N 5010 

typedef long long ll;

ll dp[N][N]; // Dynamic programming table
ll ct[N];    // Array to count occurrences of each element

// Define macro to access dp[i][asc] easily
#define DP dp[i][asc]

// Function to compute the dp value
ll r(ll i, ll asc) {
    if (asc < 0) return -2; // Invalid case
    if (i == 0) return asc ? -2 : 0; // Base case
    if (DP != -1) return DP; // If already computed, return the value

    // If current item i is counted, reduce asc by 1
    if (ct[i]) DP = r(i - 1, asc - 1);
    else DP = r(i - 1, asc);

    // Check if we can include current item i in the sequence
    if (r(i - 1, asc) != -2 && r(i - 1, asc) + ct[i] <= asc) {
        if (DP == -2 || r(i - 1, asc) + ct[i] < DP) DP = r(i - 1, asc) + ct[i];
    }
    return DP;
}

#define G(x) int x; cin >> x; // Macro to read an integer
#define F(i, a, b) for (int i = (a); i < (b); ++i) // Forward loop
#define FD(i, a, b) for (int i = (a); i > (b); --i) // Backward loop

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    G(tc) // Read number of test cases
    while (tc--) {
        G(n) // Read the size of the array

        // Initialize dp array with -1
        F(i, 0, n + 1) fill_n(dp[i], n + 1, -1);
        
        // Read the elements of the array and count their occurrences
        F(i, 0, n) {
            G(x)
            ct[x]++;
        }

        ll ans = n;

        // Find the maximum valid asc value
        FD(i, n, -1) if (r(n, i) != -2) {ans = i;

        /*cout << ans << endl;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                cout << setw(3) << dp[j][i] << " ";
            }
            cout << endl;
        }
        */}

        cout << ans << endl;
        cout << "-------------------" << endl;
        // Reset the count array for the next test case
        fill_n(ct, n + 1, 0ll);
    }

    return 0;
}

