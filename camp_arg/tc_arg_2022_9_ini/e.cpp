#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int n, a, b, e;
    cin >> n >> a>> b;
    int cont = 0;
    int disp = 0;
    for(int i = 0; i < n; i++) {
        cin >> e;
        if(e == 1) {
            if(a == 0) {
                if(b == 0) {
                    if(disp == 0) {
                        cont++;
                    } 
                    else {
                        disp--;
                    }
                }
                else {
                    b--;
                    disp++;
                }
            }
            else {
                a--;
            }
        }
        else {
            if(b == 0) {
                cont += 2;
            }
            else {
                b--;
            }
        }
    }

    cout << cont;
    return 0;
}