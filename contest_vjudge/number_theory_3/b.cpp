#include<bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 1e6 + 6;
bool es_primo[MX];
vector <ll> primos;

void criba(ll n) {
    fill(es_primo, es_primo + n + 1, true);
    es_primo[0] = es_primo[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (es_primo[i]) {
            for (ll j = i * i; j <= n; j += i) {
                es_primo[j] = false;
            }
        }
    }
    for(ll i = 2; i <= n; i++) {
        if(es_primo[i]){
            primos.push_back(i);
        }
    }
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

int main() {
    inic;
    inic1;
    inic2;
    criba(1000006);
    int t;
    cin >> t;
    while(t--) {
        ll a,b,c,phi, ans;
        cin >> a >> b >> c;
        if(b < 0) {
            //phi(n)=n*(1-1/p1)*(1-1/p2)*...  pi -> prime divisors
            if(es_primo[c]) {
                phi = c - 1;
            }
            else {
                phi=c;
                ll l = primos.size();
                for(ll i = 0; i <= l && primos[i] <= c; i++) {
                    if(c % primos[i] == 0) {
                        phi*=(primos[i]-1);
                        phi /= primos[i];
                    }
                }
            }
            b=-b;
            //inv_mod
            ans=pot_mod(a,phi - 1,c);

            ans=pot_mod(ans,b,c);
        }
        else {
            ans=pot_mod(a,b,c);
        }
        cout << ans << '\n';
    }
    return 0;
}