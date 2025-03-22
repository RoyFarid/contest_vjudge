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
       // 3 4 6 6
       // 9 - m >= x && 9 - m <= y
       // suma-e-m >= x && suma-e-m <= y
       // m >= suma-e-y && m <= suma-e-x
       // m >= lowerbound(suma-e-y) && m <= upperbound(suma-e-x)
       ll cant = 0;
       for(int i = 0; i < n; i++) {
            cant += (upper_bound(arr.begin() + i + 1, arr.end(), suma-arr[i]-x) - lower_bound(arr.begin() + i + 1, arr.end(), suma-arr[i]-y));
            //cout << cant << " ";
       }
       //cout << endl;
       cout << cant << "\n";

            
    }
    return 0;
}