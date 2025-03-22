#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MX = 2e5 + 5;

ll fact[MX], inv_fact[MX];

ll pot_mod(ll a, ll b, ll p) {
    ll res = 1;
    a %= p;
    while (b > 0) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

void precomp() {
    fact[0] = 1;
    for (ll i = 1; i < MX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MX - 1] = pot_mod(fact[MX - 1], MOD - 2, MOD);
    for (ll i = MX - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

ll comb(ll n, ll k, ll p) {
    if (k > n) return 0;
    return (((fact[n] * inv_fact[k]) % p) * inv_fact[n - k]) % p;
}

int main() {
    inic;
    inic1;
    inic2;
    precomp();
    
    int t;
    cin >> t;
    while (t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        ll up = 2 * n;
        ll exp = comb(up, n, MOD);
        if (b == 0) exp = 1;
        ll res = pot_mod(exp, b, MOD);
        if (a == 0 && res > 0) {
            cout << "0\n";
            continue;
        }

        ll sol = pot_mod(a, res, MOD);
        cout << sol << '\n';
    }
    return 0;
}