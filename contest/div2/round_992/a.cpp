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
        double n;
        cin >> n;
        if(n == 1) {
            cout << 1 << '\n';
        }
        else {
            int cont = 1;
            while(n > 1) {
                n = ceil(n/2) - 1;
                cont++;
            }
            cout << cont << '\n';
        }
    }
            
    return 0;
}