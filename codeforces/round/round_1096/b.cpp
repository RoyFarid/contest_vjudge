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
        int n; cin >> n;
        int cont = 0;
        for(int i = 0; i < n; i++) {
            char e; cin >> e;
            if(e== '(') cont++;
            else cont--;
        }
        if(cont  == 0) cout << "YES" << sl;
        else cout << "NO" << sl;
    }
    return 0;
}