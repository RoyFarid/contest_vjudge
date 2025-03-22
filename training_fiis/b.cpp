#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
 
int main () {
    inic;
    inic1;
    inic2;
    ll a,b,c,d;
    ll t;
    cin >> t; 
    while(t--){
        cin >> a >> b >> c >> d;
        ll x,y;
        bool f = false;
        for(ll i = a+1 ; i <= c; i++) {
            ll q = (a*b) / __gcd(a*b, i);
            if(b/q < d/q) {
                x = i;
                y = (b/q + 1) * q;
                f = true;
                break;
            } 
        }

        if(f) {
            cout << x << " " << y;
        }

        else {
            cout << "-1 -1";
        }
            
        cout << "\n";
    }
    
    return 0;
}