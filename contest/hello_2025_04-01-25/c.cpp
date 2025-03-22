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
        ll l, r;
        cin >> l >> r;
        ll a,b,c = r;
        ll max = -1;
        ll op = (a^b) + (b^c) + (a^c);
        for(ll i = l; i < r - 1; i++) {
            for(ll j = l; j < r - 1;j++) {
                if(((i^j) + (j^c) + (i^c)) > max) {
                    max = ((i^j) + (j^c) + (i^c));
                    a = i;
                    b = j;
                }
            }
        }

        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}