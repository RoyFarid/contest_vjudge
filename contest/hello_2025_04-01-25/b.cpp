#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector <ll> v;
        vector <ll> c;
        ll element;
        for(ll i = 0; i < n; i++) {
            cin >> element;
            v.push_back(element);
        }  
        sort(v.begin(), v.end());
        ll cant = 1;
        for(ll i = 1; i < n; i++) {
            if(v[i] == v[i-1]) {
                cant++;
            }
            else {
                c.push_back(cant);
                cant = 1;
            }
        }
        c.push_back(cant);
        sort(c.begin(), c.end());
        ll suma = 0;
        ll desc = 0;
        ll l = c.size();
        for(ll i = 0; i < l; i++) {
            suma += c[i];
            if(suma > k) {
                desc = i;
                break;
            }
        }
        if(suma <= k) {
            desc = l - 1;
        }
        cout << l - desc << "\n";
    }    
        
    return 0;
}