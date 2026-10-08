#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
#define sl '\n'

bool f(ll n, int a, int b) {
    while(n > 0) {
        int c = n % 10;
        if(c < a || c > b) return false;
        n/= 10;
    }
    return true;
}

int c_c(ll n) {
    int cont = 0;
    while(n > 0) {
        n/= 10;
        cont++;
    }
    return cont;
}

int main() {
    inic;
    inic1;
    inic2;
    int t = 1;
    //cin >> t;
    while(t--) {
        int a, b, m, r;
        cin >> a >> b >> m >> r;
        bool wa = 0;
        for(ll k = 0; k < 1e8; k++) {
            ll i = m * k + r;
            if(f(i, a, b)) {
                wa = 1;
                cout << c_c(i) << sl;
                break;
            } 
        }
        if(!wa) cout << -1 << sl;
    }
    return 0;
}
