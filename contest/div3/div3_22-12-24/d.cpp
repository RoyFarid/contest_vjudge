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
       ll n, x, y, suma = 0, posini = 0;
       cin >> n >> x >> y;
       vector <ll> arr(n);
       for(int i = 0; i < n; i++) {
            cin >> arr[i];
            suma += arr[i];
       }
       sort(arr.begin(), arr.end());
       if(x > suma-arr[0]-arr[1] || y < suma -arr[n-1]-arr[n-2]) {
            cout << "0\n";
       }

       else {
        ll cont = 0;
        bool entro = false;
        bool cerrar = true;
            for(int i = 0; i < n-1 && cerrar; i++) {
                for(int j = i + 1; j < n && cerrar; j++) {
                    cont++;
                    if((suma - arr[i]-arr[j]) >= x && (suma - arr[i] - arr[j]) <= y) {
                        posini++;
                        entro = true;
                    }
                    if(entro && !((suma - arr[i]-arr[j]) >= x && (suma - arr[i] - arr[j]) <= y)) {
                        cerrar = false;
                    }
                }
            }
            cout << posini << "\n";
       }     
            
    }
    return 0;
}