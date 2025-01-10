#include <bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef unsigned long long  ull ;
typedef vector<ll> vl ;
typedef  vector<vl>vvl;
const ll MOD = 1e9 + 7;
int main() {
	ull n, k, o, p;
	cin >> n >> k >> o >> p;
	ull comb = 1;
	ull cur = 1;
	for (int i = 0;  i < k; i++) {
	    cur = (cur * p) % MOD;
	    comb = (comb + cur) % MOD;
	}
	//cout << comb << endl;
	// Fuck that double inf >:(
	//ull ans = (ull)powl(comb, n+1) % MOD * (ull)powl(o, n) % MOD;
	ull ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * comb) % MOD;
        ans = (ans * o) % MOD;
    }
    ans = (ans * comb) % MOD;

	cout << ans << endl;
	return 0;
}