#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 1e9 + 7;

// Exponenciación modular
ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Suma geométrica modular
ll geometric_sum(ll a, ll r, ll n, ll mod) {
    if (r == 1) {
        return (a * n) % mod; // Caso especial: razón = 1
    }
    ll num = (mod_exp(r, n, mod) - 1 + mod) % mod; // (r^n - 1) mod mod
    ll den = (r - 1 + mod) % mod;                  // (r - 1) mod mod
    ll den_inv = mod_exp(den, mod - 2, mod);       // Inverso modular de (r - 1)
    return (a * num % mod * den_inv % mod) % mod;
}

int main() {
    inic;
    inic1;
    inic2;
    string s;
    ll k;
    cin >> s >> k;
    ll l = s.size();
    ll suma = 0;

    // Preprocesar las posiciones relevantes (dígitos '0' y '5')
    vector<ll> positions;
    for (ll i = 0; i < l; i++) {
        if (s[i] == '0' || s[i] == '5') {
            positions.push_back(i);
        }
    }

    // Calcular la suma para cada posición relevante
    for (ll pos : positions) {
        ll first_exp = l * k - (pos+1); // Primer exponente
        suma = (suma + geometric_sum(mod_exp(2, first_exp, MX), mod_exp(2, l, MX), k, MX)) % MX;
    }

    cout << suma << endl;

    return 0;
}