#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
// Function to compute binomial coefficients (Newton's forward difference)
vector<int> shiftPolynomial(const vector<int>& poly, int K) {
    int N = poly.size() - 1;
    vector<int> shifted(N + 1, 0);
    vector<int> factorial(N + 1, 1), invFactorial(N + 1, 1);
    
    // Compute factorials and modular inverses
    for (int i = 2; i <= N; i++) {
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    }
    invFactorial[N] = 1; // Assume modular inverse of factorial[N] is precomputed
    for (int i = N - 1; i >= 1; i--) {
        invFactorial[i] = (1LL * invFactorial[i + 1] * (i + 1)) % MOD;
    }
    
    // Compute the shifted polynomial coefficients
    for (int i = 0; i <= N; i++) {
        long long term = 1;
        for (int j = i; j <= N; j++) {
            shifted[j] = (shifted[j] + term * poly[i] % MOD * factorial[j] % MOD * invFactorial[i] % MOD * invFactorial[j - i] % MOD) % MOD;
            term = term * K % MOD;
        }
    }
    return shifted;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> t(N + 1), p(N + 1);
    
    for (int i = 0; i <= N; i++) cin >> t[i];
    for (int i = 0; i <= N; i++) cin >> p[i];
    
    vector<int> t_shifted = shiftPolynomial(t, K);
    vector<int> p_shifted = shiftPolynomial(p, -K);
    
    vector<int> q(N + 1);
    for (int i = 0; i <= N; i++) {
        q[i] = (t_shifted[i] + p_shifted[i]) % MOD;
    }
    
    for (int i = 0; i <= N; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
    
    return 0;
}