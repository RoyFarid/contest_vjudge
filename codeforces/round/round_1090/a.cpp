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
        vector <int> v(7);
        for(int &e : v) {
            cin >> e;
        }
        int m = -68;
        int sum = 0;
        for(int i = 0; i < 7; i++) {
            sum -= v[i];
            m = max(m, v[i]);
        }
        int ans  = sum + 2*m;
        cout << ans << sl; 
    }
    return 0;
}