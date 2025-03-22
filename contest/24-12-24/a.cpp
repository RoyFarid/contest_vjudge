#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

bool esprimo(ll num) {
    if (num == 1) {
        return false;
    }
    for(ll i = 0; i*i < num; i++) {
        if(num % i == 0 ) {
            return false;
        }
    }
    return true;
}
ll max_entero_der(ll n, ll d) {
    ll q = n / d;
    if (q * d < n) {
        q++;
    }
    return q;
}
int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while(t--) {
        ll l, r, mcd;
        cin >> l >> r >> mcd;
        ll p, q;
        p = max_entero_der(l,mcd);
        q = r / mcd;
        if (esprimo(p)) {
            if (esprimo(q)) {
                cout << mcd*p << " " << mcd * q;
            }
            else {
                if(q % p == 0) {
                    cout << "-1 -1";
                }
                else {
                    cout << mcd*p << " " << mcd * q;
                }
            }
            
        }
        else {
            cout << mcd*p << " " << mcd * q;
        }
    }
        
return 0;
}