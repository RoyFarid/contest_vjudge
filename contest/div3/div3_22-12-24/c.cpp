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
        ll n, m, k, element, suma = 0;
        cin >> n >> m >> k;
        ll listas[m+1];
        for(int i = 0; i < m; i++) {
            cin >> listas[i+1];
        }
        for(int i = 0; i < k; i++) {
            cin >> element;
            suma += element;
        }

        if (k == n) {
            for(int i = 0; i < m; i++) {
                cout << "1";
            }
           
        }
        else if (k <= n-2) {
            for(int i = 0; i < m; i++) {
                cout << "0";
            }
           
        }
        else {
            ll suma_tot = (n*(n+1)) / 2;
            for(int i = 1; i < m + 1; i++) {
                if(listas[i] == suma_tot-suma) {
                    cout << "1";
                }
                else {
                    cout << "0";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}