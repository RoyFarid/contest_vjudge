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
    int x , y , z;
    int a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    bool f = true;
    if(a < x) {
        f = false;
    }
    else {
        if(a - x + b < y) {
            f = false;
        }
        else {
            if(a - x + b - y + c < z) {
                f = false;
            }
        }
    }
    
    if(f) cout << "YES";
    else cout << "NO";
    return 0;
}