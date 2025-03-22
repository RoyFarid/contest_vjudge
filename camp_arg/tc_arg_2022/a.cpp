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
    int a, b;
    cin >> a >> b;
    bool c;
    // c = true cargador en a
    // c = false cargador en b
    int cont = 0;
    while(a > 0 && b > 0) {
        if(a < b) c = true;
        else c = false;
        if(c) {
            a += 1;
            b -= 2;
        }
        else {
            b += 1;
            a -= 2;
        }
        cont++;
    }
    cout << cont;

    return 0;
}