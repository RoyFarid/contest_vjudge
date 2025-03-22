#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

bool absdif(int a, int b) {
    int dif = a - b;
    if(-1 <= dif && dif <= 1) {
        return true;
    }
        return false;
}
int main () {
    inic;
    inic1;
    inic2;
    int n, m; 
    cin >> n >> m;
    vector <int> arr(n+2);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    arr[0] = arr[1];
    arr[n+1] = arr[n];
    int pot = 1;
    for(int i = 1; i <= n; i++) {
        if(arr[i] == 0) {
            int cont = 0;
            arr[i] = min(arr[i-1] - 1, arr[i+1] - 1);
            if(absdif(arr[i-1], arr[i] && absdif(arr[i],arr[i+1]))) {
                cont++;
            }
            if(absdif(arr[i-1], arr[i]+1 && absdif(arr[i] + 1,arr[i+1]))) {
                cont++;
            }
            if(absdif(arr[i-1], arr[i] + 2 && absdif(arr[i] + 2,arr[i+1]))) {
                cont++;
            }
            pot*= cont;
        }
    }
    cout << pot;
    return 0;
}