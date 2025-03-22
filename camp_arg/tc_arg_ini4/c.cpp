#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n';
typedef long long ll;

int cant_cif(int n) {
    int cont = 0;
    while(n != 0) {
        cont++;
        n/= 10;
    }
    return cont;
}
int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while (t--) {
        int x; 
        cin >> x;
        int c1 = ((x % 10) - 1) * 10;
        int cant = cant_cif(x);
        int c2 = (cant * (cant + 1)) / 2; 
        int r = c1 + c2;
        cout << r << sl;
    }
    return 0;
}
