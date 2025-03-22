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
        int n;
        cin >> n;
        int e;
        bool f = false;
        int cant = 0;
        for(int i = 0; i < n; i++) {
            cin >> e;
            if(e % 2 == 1) {
                cant++;
            }
            else {
                f = true;
            }
        }
        if(f) {
            cout << cant + 1;
        }
        else {
            cout << cant - 1;
        }
        cout << "\n";
    }
        
    return 0;
}