#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 1e9 + 7;

ll pot(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MX;
        }
        base = (base * base) % MX;
        exp /= 2;
    }
    return result;
}

// sum = a* (r^n-1) / (r-1) 
ll suma_geo(ll a, ll r, ll n) {
    if (r == 1) {
        return (a * n) % MX;
    }
    ll num = (pot(r, n) - 1 + MX) % MX;
    ll den = pot(r - 1, MX - 2);
    return (a * num % MX * den % MX) % MX;
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
    for(ll i = 0; i < l; i++) {
        if(s[i] == '0' || s[i] == '5') {
            suma = (suma + suma_geo(pot(2, i), pot(2, l), k)) % MX;
        }
    }

    cout << suma;

    return 0;
}