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
        string s; cin >> s;
        int c1 = 0;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') c1++;
            v[i] = c1;
        }
        int ans = n + 1;
        if(s[0] == '1') {
            cout << n - 1 - (n - 1) << sl;
            continue; 
        }
        for(int i = 0; i < n; i++) {
            int c0 = i + 1 - v[i];
                if(s[i] == '1') ans = min(ans, (n - i - 1 - (c1 - v[i])) + i - c0);
                else {// cambiar a 1 los de delante y 0s los de atras
                    if(v[i] > 0) {
                        ans = min(ans, (n - i - 1 - (c1 - v[i])) + i - c0 + 1);
                    }
                    else {
                        // cambiar a 0s los de delante
                        ans = min(ans, c1 - v[i]);
                    }
                }
        }
        cout << ans << sl;
        
    }
    return 0;
}