#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ll l = s.size();
        ll cont = 0;
        for(ll i = 0; i < l; i++) {
            if(s[i] == '1') {
                cont++;
            }
        }
        cout << cont << "\n";
    }
    return 0;
}