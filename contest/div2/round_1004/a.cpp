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
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector <ll> a(n);
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll cont = 1;
        for(ll i = 1; i < n; i++) {
            if(a[i-1] == a[i]) {
                cont++;
            }
            else {
                if(cont >= 3) {
                    for(ll j = i + 2 - cont; j < i; j++) {
                        a[j]++;
                    }
                }
                i = i + 2 - cont;
                cont = 1;
            }
        }

        for(auto x : a) {
            cout << a << ""
        }
        vector <ll> cants;
        ll cant= 1;
        for(ll i = 1; i < n; i++) {
            if(a[i-1] == a[i]) {
                cant++;
            }
            else {
                cants.push_back(cant);
                cant = 1;
            }
        }
        bool f = true;
        for(ll x : cants) {
            if(x != 2) {
                f = false;
                break;
            }
        }
        if(f) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout << '\n';
    }
    return 0;
}