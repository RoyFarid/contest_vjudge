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

ll mult_mod(ll a, ll b, ll mod) {
    return ((a%mod) * (b%mod)) % mod;
}

ll pot_mod (ll a, ll b, ll mod) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1 == 1) {
            ans = mult_mod(ans, a, mod);
        }
        a = mult_mod(a, a, mod);
        b >>= 1;
    }
    return ans;
}

ll inv_mod(ll x, ll mod) {
    return pot_mod(x, mod - 2, mod);
}

ll comb(ll n, ll k, ll mod) {
    ll num = 1;
    ll den = 1;
    for(ll i = 0; i < k; i++) {
        num = mult_mod(num, n - i, mod);
        den = mult_mod(den, k - i, mod);
    }
    ll den_inv = inv_mod(den, mod);
    return mult_mod(num, den_inv, mod);
}

int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t; 
    while(t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        ll exp = 0;
            for(ll i = n; i >= 0; i -= 1) {
                exp = suma_mod(exp, pot_mod(comb(n, i, MOD), 2, MOD), MOD);
            }
        ll res = pot_mod(exp, b, MOD);
        ll sol = pot_mod(a, res, MOD);
        cout << exp << '\n';    
    }

    return 0;
}