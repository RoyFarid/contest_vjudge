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
        int n, a, b;
        cin >> n >> a >> b;
        bool win;
        if(a > b) {
            while(true) {
                if(a - 1 == b) {
                    a++;
                }
                
                else {
                    a--;
                }

                if(a == 0 || a == n + 1) {
                    win = false;
                    break;
                }

                if(b+ 1 == a) {
                    b--;
                }
                else {
                    b++;
                }

                if(b == 0 || b == n + 1) {
                    win = true;
                    break;
                } 
            }
        }
        else {
            while(true) {
    
                if(a+1 == b) {
                    a--;
                }
                else {
                    a++;
                }

                if(a == 0 || a == n + 1) {
                    win = false;
                    break;
                }

                if(b-1 == a) {
                    b++;
                }
                else {
                    b--;
                }

                if(b == 0 || b == n + 1) {
                    win = true;
                    break;
                }
            }
        }
        if(win) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}