#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MOD = 1e9 + 7;

ll suma_mod(ll a, ll b, ll mod) {
    if(a >= mod) {
        a -= mod;
    }
    if(b >= mod) {
        b -= mod;
    }
    if(a+b >= mod) {
        return a + b - mod;
    }
    return a + b;
}

ll pot_mod (ll a, ll b, ll mod) {
    if(b == 0) return 1 % mod;
    ll temp = pot_mod(a, b / 2, mod);
    temp = (temp * temp) % mod;
    if(b % 2 == 0) return temp;
    return (temp * (a % mod)) % mod;
}

ll inv_mod(ll x, ll mod) {
    return pot_mod(x, mod - 2, mod);
}

// suma_n_terminos
// s = a (r^n - 1) / (r-1)
ll suma_geo(ll a, ll r, ll n, ll mod) {
    ll num = (a * (pot_mod(r,n, mod)-1)) % mod;
    ll den = inv_mod(((r - 1 + mod) % mod), mod);
    return (num * den) % mod;
}

int main () {
    inic;
    inic1;
    inic2;
    ll k;
    string s;
    cin >> s >> k;
    ll l = s.size();
    ll sum = 0;
    for(ll i = 0; i < l; i++) {
        if(s[i] == '0' || s[i] == '5') {
            ll sum_g = suma_geo(pot_mod(2, i, MOD), pot_mod(2, l, MOD), k, MOD);
            //cout << sum_g << endl;
            sum = suma_mod(sum_g, sum, MOD);
        }
    }
    cout << sum;
    return 0;
}