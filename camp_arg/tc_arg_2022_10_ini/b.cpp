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
    ll n, x;
    cin >> n >> x;
    ll cont = 0;
    while(n--) {
        char op;
        ll d;
        cin >> op >> d;
        if(op == '+') {
            x += d;
        }
        else {
            if(x >= d) {
                x -= d;
            }
            else {
                cont++;
            }
        }
    }
    cout << x << " " << cont << sl;
    return 0;
}