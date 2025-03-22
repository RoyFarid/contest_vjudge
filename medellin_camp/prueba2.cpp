#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        int n;
        cin >> n >> s;
        bool f = false;
        int cont = 0;
        int pos = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                f = true;
                pos = i;
                break;
            }
        }

        //cout << pos << endl;

        if(f) {
            for(int i = pos + 1; i < n; i++) {
                if(s[i] != s[i-1]) {
                    cont++;
                }
            }
        }

        if(f) cout << cont + 1 << "\n";
        else cout << "0\n";
    }
    return 0;
}