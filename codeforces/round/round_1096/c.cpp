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
        vector <int> v(n);
        vector <bool> vis(n, 0);
        vector <int> six;
        vector <int> two;
        vector <int> three;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] % 6 == 0) {
                six.push_back(v[i]);
                vis[i] = 1;
                continue;
            }
            if(v[i] % 2 == 0) {
                two.push_back(v[i]);
                vis[i] = 1;
                continue;
            }
            if(v[i] % 3 == 0) {
                three.push_back(v[i]);
                vis[i] = 1;
                continue;
            }
        }
        for(int e : six) cout << e << " ";
        for(int e : three) cout << e << " ";
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) cout << v[i] << " ";
        }    
        for(int e : two) cout << e << " ";
        cout << sl;
    }
    return 0;
}