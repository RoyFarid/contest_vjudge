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
    ll n; 
    cin >> n;
    ll element;
    vector <ll> d;
    ll suma = 0;
    ll tot = 0;
    d.push_back(0);
    for(ll i = 0; i < n-1; i++) {
        cin >> element;
        suma += element;
        d.push_back(suma);
        tot += suma;
    }

    // n*(n+1)/2 = num * n + tot;
    ll num = (n*n + n - 2*tot) / (2*n);
    if((num * 2 * n) == (n*n + n - 2*tot)) {
        if(num >= 1 && num <= n) {
            vector <ll> original;
            for(ll j = 1; j <= n; j++) {
                original.push_back(j);
            }
            vector <ll> perm;
            for(ll i = 0; i < n; i++) {
                ll e = num + d[i];
                perm.push_back(e);
            }

            vector <ll> temp = perm;
            sort(temp.begin(), temp.end());
            if(temp == original) {
                for(ll i = 0; i < n; i++) {
                    cout << perm[i] << " ";
                }
            }
            else cout << "-1";

        }
        else cout << "-1";
    }
    else cout << "-1";
    return 0;
}