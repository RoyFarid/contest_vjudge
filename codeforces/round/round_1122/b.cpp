#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
#define sl '\n'
int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c; cin >> a >> b >> c;
        if(a == b) {
            cout << c << sl;
            continue;
        }
        if(a > b) {
            cout << a - b + c << sl;
            continue;
        }

        if((a + c - b) > (b - a)) {
            cout << a + c - b << sl;
        }
        else cout << b - a << sl;

    }
    return 0;
}