#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sl '\n' 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n; cin >> n;
        map<char,int> m;
        vector<char> v(n);
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            m[s[0]] = 1;
            v[i] = s[0];
        }
        int a,b; cin >> a >> b;
        a--;
        b--;
        int cont = v[b] - v[a] + 1;
        if(cont <= 0) {
            cout << -1 << sl;
            continue;
        }
        if(cont == 1) {
            cout << 2 << sl;
            continue;
        }
        bool f = 1;
        for(char i = v[a]; i <= v[b]; i++) {
            if(m[i] == 0) {
                f = 0;
                break;
            } 
        }
        if(f) cout << cont;
        else cout << -1; 
    }   
    return 0;
}
