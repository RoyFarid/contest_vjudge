#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n';
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char s[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        if(n == 1) {
            int cif = s[1] - '0';
            if(cif % 2 == 0) {
                cout << 2;
            }
            else {
                cout << 1;
            }
        }
        else {
            if(n % 2 == 0) {
                bool f = false;
                for(int i = 2; i <= n; i += 2) {
                    if(s[i] % 2 == 0) {
                        f = true;
                    }
                }
                if(f) {
                    cout << 2;
                }
                else {
                    cout << 1;
                }
            }
            else {
                bool f = false;
                for(int i = 1; i <= n; i += 2) {
                    if(s[i] % 2 != 0) {
                        f = true;
                    }
                }
                if(f) {
                    cout << 1;
                }
                else {
                    cout << 2;
                }
            }
        }
        cout << sl;
        // B par 2,
        // R impar 1,
    }
    return 0;
}