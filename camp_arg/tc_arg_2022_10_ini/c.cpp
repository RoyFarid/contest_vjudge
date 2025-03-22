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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int min_dist = 1e9 + 1;
    bool f = false;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == 'R' && s[i+1] == 'L') {
            int dist = (arr[i+1] - arr[i]) / 2;
            if(dist < min_dist) {
                min_dist = dist;
            }
            f = true;
        }
    }
    if(!f) {
        cout << "-1";
    }
    else {
        cout << min_dist;
    }
    return 0;
}