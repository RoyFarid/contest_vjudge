#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;
const ll MX = 1e9;
int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 4 == 0){
            int r1 = sqrt(n/2);
            int r2 = sqrt(n/4);
            if(r1*r1 == n/2 || r2 * r2 == n/4) {
                cout << "YES";
            }
            else {
                cout << "NO";
            }
        }
        else if(n % 2 == 0) {
            int r1 = sqrt(n/2);
            if(r1*r1 == n/2) {
                cout << "YES";
            }
            else {
                cout << "NO";
            }

        }
        else {
            cout << "NO";   
        }
        cout << sl;
    }
    return 0;
}