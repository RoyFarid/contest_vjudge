#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

const int MOD = 998244353;
const double PI = acos(-1);

using cd = complex<double>;
using vcd = vector<cd>;

// FFT function
void fft(vcd &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (cd &x : a)
            x /= n;
}

// Multiply two polynomials using FFT
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    vcd fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n), fb.resize(n);
    
    fft(fa, false), fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = static_cast<int>(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5)) % MOD;
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> t(N + 1), p(N + 1);
    
    for (int i = 0; i <= N; i++) cin >> t[i];
    for (int i = 0; i <= N; i++) cin >> p[i];
    
    vector<int> shift_t = {1, K};
    vector<int> shift_p = {1, -K};
    
    vector<int> t_shifted = multiply(t, shift_t);
    vector<int> p_shifted = multiply(p, shift_p);
    
    vector<int> q(N + 1);
    for (int i = 0; i <= N; i++) {
        q[i] = (t_shifted[i] + p_shifted[i]) % MOD;
    }
    
    for (int i = 0; i <= N; i++) {
        cout << q[i] << " ";
    }
    
    return 0;
}
