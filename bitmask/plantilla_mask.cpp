#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getBit(ll x, ll i) {
    return (x >> i) & 1LL;
}

void turnOn(ll &x, ll i) {
    x = x | (1LL << i);
}

void turnOff(ll &x, ll i) {
    x = x & (~(1LL << i));
}

void changeBit(ll &x, ll i) {
    x = x ^ (1LL << i);
}

int main() {
    ll n = 3;
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    // Cantidad de subconjuntos posibles
    for (ll mask = 0; mask < (1LL << n); mask++) { // O(n * 2^n)
        cout << "{";
        // Recorremos el numero: mask
        for (ll i = 0; i < n; i++) {
            if (getBit(mask, i) == 1) {
                cout << v[i] << " ";
            }
        }
        cout << "}" << endl;
    }
    return 0;
}