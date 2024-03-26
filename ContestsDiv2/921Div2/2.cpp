#include <iostream>
#include <algorithm>
using namespace std;

// Function to find the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, n;
        cin >> x >> n;

        // Distribute x among n sub-problems
        int sub_problem_difficulty = x / n;
        int remainder = x % n;

        // Calculate maximum balance
        int max_balance = 1; // Minimum possible balance is 1
        if (remainder != 0) {
            max_balance = gcd(sub_problem_difficulty + 1, sub_problem_difficulty);
            max_balance = gcd(max_balance, remainder);
        }

        // Output the maximum balance
        cout << max_balance << endl;
    }

    return 0;
}
