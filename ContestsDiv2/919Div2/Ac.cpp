#include <iostream>
#include <vector>
#include <climits> // Include the header for INT_MIN and INT_MAX

using namespace std;

// Function to count the number of integers k satisfying the constraints
int countSatisfyingIntegers(int n, vector<pair<int, int>>& constraints) {
    int minK = INT_MIN;  // Initialize the minimum possible k as negative infinity
    int maxK = INT_MAX;  // Initialize the maximum possible k as positive infinity

    for (int i = 0; i < n; ++i) {
        int a = constraints[i].first;
        int x = constraints[i].second;

        if (a == 1) {
            minK = max(minK, x);  // k must be greater than or equal to x
        } else if (a == 2) {
            maxK = min(maxK, x);  // k must be less than or equal to x
        } else {
            // If a == 3, k must not be equal to x, so narrow down the range
            minK = max(minK, x + 1);
            maxK = min(maxK, x - 1);
        }
    }

    // Count the number of integers in the valid range
    int count = maxK - minK + 1;

    return max(0, count);  // Ensure the count is non-negative
}

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;  // Number of constraints
        vector<pair<int, int>> constraints;

        // Read the constraints for this test case
        for (int i = 0; i < n; ++i) {
            int a, x;
            cin >> a >> x;
            constraints.push_back(make_pair(a, x));
        }

        // Calculate and print the number of satisfying integers
        int result = countSatisfyingIntegers(n, constraints);
        cout << result << endl;
    }

    return 0;
}
