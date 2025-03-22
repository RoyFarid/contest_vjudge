#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 6;
const ll MX = 2e5 + 5;

ll fact[MX];
void precomp() {
    fact[0] = 1;
    for (ll i = 1; i < MX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

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
    if(a == 0) return 0;
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

ll comb(ll n, ll k, ll p){
    return ((fact[n] * inv_mod(fact[k], p) % p) * inv_mod(fact[n-k], p)) % p;
}


int main() {
    ll p = 2,q = 500000003;
    ll invp = 250000002;
    inic;
    inic1;
    inic2;
    precomp();
    int t;
    cin >> t;
    while(t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        ll remq = fact[2 * n] * pot_mod(fact[n] * fact[n] % q,q - 2,q) % q;
        ll x = remq * p * invp % MOD2;
        x = pot_mod(x,b,MOD2);
        x = pot_mod(a,x,MOD); 
        cout << x << '\n';
    }
    return 0;
}