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
        int e = n + 1;
        for(int i = 0; i < 3*n; i++) {
            if(i % 3 == 0) {
                cout << i/3 + 1 << " ";
            }
            else {
                cout << e << " ";
                e++;
            }
        }
        cout << sl;
    }
    return 0;
}