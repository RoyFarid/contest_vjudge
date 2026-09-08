#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(0);
#define inic1 cin.tie(0);
#define inic2 cout.tie(0);
typedef long long ll;
#define sl '\n'

int main() {
    inic
    inic1
    inic2
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int e = 1;
        cout << e << " ";
        for(int i = 2; i <= n; i++) {
            cout << e*(e+2) << " ";
            e+=2;
        }
        cout << sl;
    }
    return 0;
}