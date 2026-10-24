#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sl '\n' 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        bool f1 = 0;
        bool f2 = 0;
        for(int i = 0; i < n; i++) {
            int e; cin >> e;
            if(e == 1) f1 = 1;
            if(e == 67) f2 = 1;
        }
        if(f2) cout << "YES";
        else cout << "NO";
        cout << sl;
    }   
    return 0;
}
