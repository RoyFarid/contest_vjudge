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
        int x, y; cin >> x >> y;
        if(x % 2 == 1 && y % 2 == 1) {
            cout << "NO" << sl;
            continue;
        }
        cout << "YES" << sl;
    }
    return 0;
}