#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n';
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while (t--) {
        ll n, m, suma = 0, e;
        cin >> n >> m;
        for(ll i = 0; i < n; i++) {
            cin >> e;
            suma += e;
        }
        cout << min(suma, m) << sl;
    }
    return 0;
}