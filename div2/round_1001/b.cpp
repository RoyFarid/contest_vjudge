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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector <int> v(n);
        bool ans = 1;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        for(int i = 0; i < n; i++) {
            if(v[i] <= max((n - i - 1)*2,i*2)) {
                cout << "NO" << sl;
                ans = 0;
                break;
            }
            
        }
        if (ans == 1) cout << "YES" << sl;

    }
    return 0;
}