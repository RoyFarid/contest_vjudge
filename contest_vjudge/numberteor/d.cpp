#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 1e5 + 5;

int main() {
    inic;
    inic1;
    inic2;
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll max_val = 0;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] > max_val) {
            max_val = v[i];
        }
    }

    vector<ll> cant(MX, 0);
    for (ll i = 0; i < n; i++) {
        cant[v[i]]++;
    }

    ll max_cont = 1; 
    //idea de criba
    for (ll d = 2; d <= max_val; d++) {
        ll cont = 0;

        for (ll m = d; m <= max_val; m += d) {
            cont += cant[m];
        }
        if(cont > max_cont){
            max_cont = cont;
        }
    }
    cout << max_cont;
    return 0;
}