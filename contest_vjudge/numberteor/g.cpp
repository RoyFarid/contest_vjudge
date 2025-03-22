#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 15000000;

int main() {
    inic;
    inic1;
    inic2;
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll max_val = 0;
    bool f = true;
    ll gcd = 0;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        gcd = __gcd(gcd, v[i-1]);
        if(v[i] > max_val) {
            max_val = v[i];
        }
        if(i > 0) {
            if(v[i] != v[i-1]) {
                f = false;
            }
        }
    }
    vector<ll> cant(MX, 0);
    for (ll i = 0; i < n; i++) {
        cant[v[i]]++;
    }

    ll max_cont = 1; 
    for (ll d = gcd + 1; d <= max_val; d++) {
        ll cont = 0;
        for (ll m = d; m <= max_val; m += d) {
            cont += cant[m];
        }
        if(cont > max_cont){
            max_cont = cont;
        }
    }
    
    if(!f) {
        ll result = n - max_cont;
        if(result == 0) {
            cout << "-1";
        }
        else {
            cout << result;
        }
    }
    else {
        cout << "-1";
    }
    return 0;
}