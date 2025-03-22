#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

bool cp(ll n) {
    ll r = sqrt(n);
    if(r * r == n) {
        return true;
    }
        return false;
}

int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll sum = (n * (n + 1)) / 2;
        if(cp(sum)) {
            cout << -1;
        }
        else {
            vector <int> p;
            p.push_back(2);
            p.push_back(1);
            ll pend = -1;
            ll pos = -1;
            for(int i = 3; i <= n; i++) {
                if(i == 57121) {
                    p.push_back(57122);   
                    continue;
                }
                if(i == 57122) {
                    p.push_back(57121);
                    continue;
                }
                if(i == 332928) {
                    p.push_back(332929);   
                    continue;
                }
                if(i == 332929) {
                    p.push_back(332928);
                    continue;
                }
                int number = (i* (i+1)) / 2;
                if(cp(number)) {
                    pend = i;
                    pos = i;
                    continue;
                }
                p.push_back(i);
                if(i == pos + 1) {
                    p.push_back(pend);
                }
            }
            /* ll suma = 0;
            ll cont = 0;
            vector <ll> posi;
            for(int i = 0; i < p.size(); i++) {
                suma += p[i];
                if(cp(suma)) {
                    posi.push_back(p[i]);
                    cont++;
                }
            } */
            for(ll e : p) {
                cout << e << " ";
            }
            //cout << sl << cont << sl;
        }
        cout << sl;
    }
    return 0;
}